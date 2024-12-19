#ifndef __ALLOC_REG
#define __ALLOC_REG

#include <set>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include "asm_arm.h"
#include "graph.hpp"

// 寄存器信息结构体
struct RegInfo {
    int regNum;    // 虚拟寄存器编号
    int color;     // 物理寄存器编号
    bool is_spill; // 是否需要溢出
    bool bit_map;  // 是否在栈中
    int degree;    // 节点度数，用于简化阶段
};

// 指令节点结构体，用于存储指令的使用和定义信息
struct InstructionNode {
    ASM::AS_stm *raw;
    std::set<int> use;
    std::set<int> def;
    std::set<int> in;
    std::set<int> out;
    std::set<int> previous_in;
    std::set<int> previous_out;
    std::set<InstructionNode *> sucessor;

    InstructionNode(ASM::AS_stm *raw, const std::set<int> &use, const std::set<int> &def,
                    const std::set<int> &in, const std::set<int> &out)
        : raw(raw), use(use), def(def), in(in), out(out), sucessor({}), previous_out({}), previous_in({}) {}
};

// 函数声明
void getDefReg(ASM::AS_reg *reg, std::vector<ASM::AS_reg *> &defs);
void getUseReg(ASM::AS_reg *reg, std::vector<ASM::AS_reg *> &uses);
void forwardLivenessAnalysis(std::list<InstructionNode *> &liveness, std::list<ASM::AS_stm *> &as_list);
void setControlFlowDiagram(std::list<InstructionNode *> &nodes, std::unordered_map<std::string, InstructionNode *> &blocks);
void livenessAnalysis(std::list<InstructionNode *> &nodes, std::list<ASM::AS_stm *> &as_list);

// 寄存器分配主函数
void allocateRegisters(GRAPH::Graph<RegInfo> &interferenceGraph, std::unordered_map<int, GRAPH::Node<RegInfo> *> &regNodes, std::unordered_map<int, int> &vreg_to_preg);

// 辅助函数声明
void simplify(GRAPH::Graph<RegInfo> &graph, std::unordered_map<int, GRAPH::Node<RegInfo> *> &regNodes, std::stack<GRAPH::Node<RegInfo> *> &reg_stack, int K);
bool selectSpill(GRAPH::Graph<RegInfo> &graph, std::unordered_map<int, GRAPH::Node<RegInfo> *> &regNodes, std::stack<GRAPH::Node<RegInfo> *> &reg_stack, int K);
void assignColors(GRAPH::Graph<RegInfo> &graph, std::stack<GRAPH::Node<RegInfo> *> &reg_stack, std::unordered_map<int, int> &vreg_to_preg, int K);

// 溢出处理函数
void handleSpills(std::list<ASM::AS_stm *> &as_list, const std::set<int> &spilled_vregs, std::unordered_map<int, int> &vreg_to_preg);

#endif
