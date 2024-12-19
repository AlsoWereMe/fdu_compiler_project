#include "allocReg.h"
using namespace std;
using namespace ASM;
#include <cassert>
#include <stack>
#include "printASM.h"
#include "register_rules.h"
#define MYDEBUG() printf("%s:%d\n", __FILE__, __LINE__)
#include <sstream>
#include <iostream>
#include "printASM.h"

using namespace GRAPH;

// 调试宏
#define MYDEBUG() printf("%s:%d\n", __FILE__, __LINE__)

// 全局寄存器栈
stack<Node<RegInfo> *> reg_stack;

// 获取指令中的定义和使用寄存器
void getAllRegs(AS_stm *stm, vector<AS_reg *> &defs, vector<AS_reg *> &uses)
{
    switch (stm->type)
    {
    case AS_stmkind::BINOP:
        getDefReg(stm->u.BINOP->dst, defs);
        getUseReg(stm->u.BINOP->left, uses);
        getUseReg(stm->u.BINOP->right, uses);
        break;
    case AS_stmkind::MOV:
        getDefReg(stm->u.MOV->dst, defs);
        getUseReg(stm->u.MOV->src, uses);
        break;
    case AS_stmkind::LDR:
        getDefReg(stm->u.LDR->dst, defs);
        getUseReg(stm->u.LDR->ptr, uses);
        break;
    case AS_stmkind::STR:
        getUseReg(stm->u.STR->src, uses);
        getUseReg(stm->u.STR->ptr, uses);
        break;
    case AS_stmkind::CMP:
        getUseReg(stm->u.CMP->left, uses);
        getUseReg(stm->u.CMP->right, uses);
        break;
    case AS_stmkind::ADR:
        getDefReg(stm->u.ADR->reg, defs);
        break;
    default:
        break;
    }
}

// 获取定义寄存器
void getDefReg(AS_reg *reg, vector<AS_reg *> &defs)
{
    if (!reg)
    {
        return;
    }
    switch (reg->type)
    {
    case AS_type::Xn:
    case AS_type::Wn:
    {
        defs.push_back(reg);
        break;
    }
    case AS_type::ADR:
    {
        assert(0);
    }

    default:
        break;
    }
}

// 获取使用寄存器
void getUseReg(AS_reg *reg, vector<AS_reg *> &uses)
{
    if (!reg)
    {
        return;
    }
    switch (reg->type)
    {
    case AS_type::Xn:
    case AS_type::Wn:
    {
        uses.push_back(reg);
        break;
    }
    case AS_type::ADR:
    {
        if (reg->u.add->base->type == AS_type::Xn)
        {
            uses.push_back(reg->u.add->base);
        }
        if (reg->u.add->reg)
        {
            uses.push_back(reg->u.add->reg);
        }
        break;
    }

    default:
        break;
    }
}

// 虚拟寄存器映射到物理寄存器
void vreg_map(AS_reg *reg, unordered_map<int, Node<RegInfo> *> &regNodes)
{
    switch (reg->type)
    {
    case AS_type::Xn:
    case AS_type::Wn:
    {
        int regNo = reg->u.offset;
        if (regNo < 100)
            return;
        reg->u.offset = regNodes[regNo]->info.color;
        break;
    }
    case AS_type::ADR:
    {
        assert(0);
    }
    default:
        break;
    }
}

// 前向活跃性分析
void forwardLivenessAnalysis(std::list<InstructionNode *> &liveness, std::list<AS_stm *> &as_list)
{
    unordered_map<string, InstructionNode *> blocks;
    for (const auto &stm : as_list)
    {
        InstructionNode *node = new InstructionNode(stm, {}, {}, {}, {});
        liveness.push_back(node);
        vector<AS_reg *> defs;
        vector<AS_reg *> uses;

        switch (stm->type)
        {
        case AS_stmkind::LABEL:
            blocks.emplace(stm->u.LABEL->name, node);
        default:
            getAllRegs(stm, defs, uses);
            break;
        }

        for (auto &x : defs)
        {
            if (x->u.offset >= 100)
            {
                node->def.emplace(x->u.offset);
            }
            assert(x->type != AS_type::ADR);
        }

        for (auto &x : uses)
        {
            if (x->u.offset >= 100)
            {
                node->use.emplace(x->u.offset);
            }
            assert(x->type != AS_type::ADR);
        }
    }

    setControlFlowDiagram(liveness, blocks);
}

// 设置控制流图
void setControlFlowDiagram(std::list<InstructionNode *> &nodes, unordered_map<string, InstructionNode *> &blocks)
{
    for (auto it = nodes.begin(); it != nodes.end(); ++it)
    {
        InstructionNode *currentNode = *it; // 当前节点
        InstructionNode *nextNode = nullptr;
        auto nextIt = std::next(it); // 获取下一个元素的迭代器
        if (nextIt != nodes.end())
        {
            nextNode = *nextIt; // 如果存在下一个节点，则获取它
        }
        switch (currentNode->raw->type)
        {
        case AS_stmkind::RET:

            break;
        case AS_stmkind::B:
            currentNode->sucessor.emplace(blocks[currentNode->raw->u.B->jump->name]);
            break;
        case AS_stmkind::BCOND:
            currentNode->sucessor.emplace(blocks[currentNode->raw->u.BCOND->jump->name]);
            if (nextNode)
            {
                currentNode->sucessor.emplace(nextNode);
            }
            break;
        default:
            if (nextNode)
            {
                currentNode->sucessor.emplace(nextNode);
            }
            break;
        }
    }
}

// 初始化干扰图和节点
void init(std::list<InstructionNode *> &nodes, std::unordered_map<int, Node<RegInfo> *> &regNodes, Graph<RegInfo> &interferenceGraph, std::list<ASM::AS_stm *> &as_list)
{
    assert(reg_stack.empty());
    bool changed;

    int set_size = 0;
    do
    {
        changed = false;
        for (auto it = nodes.rbegin(); it != nodes.rend(); ++it)
        {
            InstructionNode *n = *it;
            n->previous_in = n->in;
            n->previous_out = n->out;

            if (n->sucessor.size())
                for (InstructionNode *s : n->sucessor)
                {
                    n->out.insert(s->in.begin(), s->in.end());
                }

            n->in.clear();
            std::set_difference(n->out.begin(), n->out.end(), n->def.begin(), n->def.end(), std::inserter(n->in, n->in.end()));
            n->in.insert(n->use.begin(), n->use.end());
            set_size += n->in.size();

            if (n->in != n->previous_in || n->out != n->previous_out)
            {
                changed = true;
            }
        }

    } while (changed);
    set<int> regs;
    set<int> defs;
    set<int> uses;

    for (auto &x : nodes)
    {
        defs.insert(x->def.begin(), x->def.end());
        uses.insert(x->use.begin(), x->use.end());
    }

    regs.insert(defs.begin(), defs.end());
    regs.insert(uses.begin(), uses.end());
    int ijj = 0;
    for (auto x : regs)
    {
        regNodes.insert({x, interferenceGraph.addNode({x, x, false, false, 0})});
    }

    for (auto x : nodes)
    {
        std::vector<int> vec(x->in.begin(), x->in.end());
        for (int i = 0; i < vec.size(); i++)
        {
            for (int j = i + 1; j < vec.size(); j++)
            {
                interferenceGraph.addEdge(regNodes[vec[i]], regNodes[vec[j]]);
                interferenceGraph.addEdge(regNodes[vec[j]], regNodes[vec[i]]);
            }
        }
    }

    // 设置节点的度数
    auto nodes_ = interferenceGraph.nodes();
    for (auto &nodePair : *nodes_)
    {
        Node<RegInfo> *node = nodePair.second;
        NodeSet *successors = node->succ();
        node->info.degree = successors->size();
    }

    // 删除不使用的指令
    std::set<int> to_delete;
    std::set_difference(defs.begin(), defs.end(), uses.begin(), uses.end(), std::inserter(to_delete, to_delete.end()));

    for (auto &x : nodes)
        delete x;

    for (auto it = as_list.begin(); it != as_list.end();)
    {
        vector<AS_reg *> defs;
        vector<AS_reg *> uses;
        getAllRegs(*it, defs, uses);
        int n = 0;
        if (defs.size() > 0)
        {
            int regNo = defs.front()->u.offset;
            if (to_delete.find(regNo) != to_delete.end())
            {
                it = as_list.erase(it);
                continue;
            }
        }
        it++;
    }
}

// 主活跃性分析函数
void livenessAnalysis(std::list<InstructionNode *> &nodes, std::list<ASM::AS_stm *> &as_list)
{
    Graph<RegInfo> interferenceGraph;
    unordered_map<int, Node<RegInfo> *> regNodes;
    init(nodes, regNodes, interferenceGraph, as_list);

    // 寄存器分配
    unordered_map<int, int> vreg_to_preg;
    allocateRegisters(interferenceGraph, regNodes, vreg_to_preg);

    // 映射寄存器
    for (auto &x : as_list)
    {
        // 根据 vreg_to_preg 映射虚拟寄存器到物理寄存器
        // 需要实现具体的映射逻辑，这里简要示例
        // 例如：
        // if (x->type == AS_stmkind::MOV) {
        //     map x->u.MOV->dst and x->u.MOV->src
        // }
    }

    // TODO: 根据寄存器分配结果修改 as_list，插入spill代码
}

// 图着色算法实现
void allocateRegisters(Graph<RegInfo> &interferenceGraph, unordered_map<int, Node<RegInfo> *> &regNodes, unordered_map<int, int> &vreg_to_preg)
{
    const int K = 16;

    // 简化阶段
    simplify(interferenceGraph, regNodes, reg_stack, K);

    // 分配颜色
    assignColors(interferenceGraph, reg_stack, vreg_to_preg, K);

    // 处理溢出
    std::set<int> spilled_vregs;
    for (auto &pair : vreg_to_preg)
    {
        if (pair.second == -1)
        {
            spilled_vregs.insert(pair.first);
        }
    }

    if (!spilled_vregs.empty())
    {
        handleSpills(*(new std::list<ASM::AS_stm *>()), spilled_vregs, vreg_to_preg);
    }
}


// 简化阶段：移除度数小于 K 的节点
void simplify(Graph<RegInfo> &graph, std::unordered_map<int, Node<RegInfo> *> &regNodes, std::stack<Node<RegInfo> *> &reg_stack, int K)
{
    bool progress = true;
    while (progress)
    {
        progress = false;
        for (auto it = graph.mynodes.begin(); it != graph.mynodes.end();)
        {
            Node<RegInfo> *node = it->second;
            if (node->info.degree < K)
            {
                reg_stack.push(node);
                // 移除节点，并减少邻居的度数
                for (auto &succ_key : *(node->succ()))
                {
                    // 查找后继节点
                    auto succ_it = graph.mynodes.find(succ_key);
                    if (succ_it != graph.mynodes.end())
                    {
                        Node<RegInfo>* succ_node = succ_it->second;
                        succ_node->info.degree--;
                        // 移除边
                        graph.rmEdge(node, succ_node);
                        graph.rmEdge(succ_node, node);
                    }
                }
                // 移除节点
                it = graph.mynodes.erase(it);
                progress = true;
            }
            else
            {
                ++it;
            }
        }
    }
}

// 溢出选择阶段：选择一个节点进行溢出
bool selectSpill(Graph<RegInfo> &graph, std::unordered_map<int, Node<RegInfo> *> &regNodes, std::stack<Node<RegInfo> *> &reg_stack, int K)
{
    // 选择度数最大的节点进行溢出
    int max_degree = -1;
    Node<RegInfo> *spill_node = nullptr;
    for (auto &nodePair : graph.mynodes)
    {
        Node<RegInfo> *node = nodePair.second;
        if (node->info.degree > max_degree)
        {
            max_degree = node->info.degree;
            spill_node = node;
        }
    }

    if (spill_node)
    {
        // 标记为溢出
        spill_node->info.is_spill = true;

        // 从图中移除该节点
        graph.rmNode(spill_node);

        // 将其放入简化栈
        reg_stack.push(spill_node);

        return true;
    }

    return false;
}

// 分配颜色阶段
void assignColors(Graph<RegInfo> &graph, std::stack<Node<RegInfo> *> &reg_stack, std::unordered_map<int, int> &vreg_to_preg, int K)
{
    while (!reg_stack.empty())
    {
        Node<RegInfo> *node = reg_stack.top();
        reg_stack.pop();

        // 获取邻居的颜色
        std::set<int> neighbor_colors;
        for (auto &succ_key : *(node->succ()))
        {
            auto it = graph.mynodes.find(succ_key);
            if (it != graph.mynodes.end())
            {
                Node<RegInfo>* succ_node = it->second;
                if (succ_node->info.color != -1)
                {
                    neighbor_colors.insert(succ_node->info.color);
                }
            }
        }

        // 分配一个未被占用的颜色
        int color = -1;
        for (int i = 0; i < K; i++)
        {
            if (neighbor_colors.find(i) == neighbor_colors.end())
            {
                color = i;
                break;
            }
        }

        if (color == -1)
        {
            node->info.is_spill = true;
        }
        else
        {
            vreg_to_preg[node->info.regNum] = color;
        }
    }
}


// 处理溢出
void handleSpills(std::list<ASM::AS_stm *> &as_list, const std::set<int> &spilled_vregs, std::unordered_map<int, int> &vreg_to_preg)
{
    for (auto &stm : as_list)
    {
        switch (stm->type)
        {
        case AS_stmkind::MOV:
            if (spilled_vregs.find(stm->u.MOV->dst->u.offset) != spilled_vregs.end())
            {
                // 将 dst 寄存器从栈中加载
            }
            break;
        default:
            break;
        }
    }
}
