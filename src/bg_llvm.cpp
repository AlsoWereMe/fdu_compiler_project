#include "bg_llvm.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
#include "graph.hpp"
#include "printLLVM.h"
#include "temp.h"

/* Graph on AS_ basic blocks. This is useful to find dominance
   relations, etc. */

using namespace std;
using namespace LLVMIR;
using namespace GRAPH;

static Graph<L_block *> RA_bg;
static unordered_map<Temp_label *, L_block *> block_env;

Graph<L_block *> &Bg_graph() {
    return RA_bg;
}

unordered_map<Temp_label *, L_block *> &Bg_block_env() {
    return block_env;
}

Node<L_block *> *Look_bg(L_block *b) {
    // Look for the node associated with block 'b' in RA_bg
    for (auto &n : *RA_bg.nodes()) {
        if (n.second->nodeInfo() == b) {
            return n.second;
        }
    }
    // If not found, add it and return the node
    return RA_bg.addNode(b);
}

static void Enter_bg(L_block *b1, L_block *b2) {
    Node<L_block *> *n1 = Look_bg(b1);
    Node<L_block *> *n2 = Look_bg(b2);
    RA_bg.addEdge(n1, n2);
}

Graph<L_block *> &Create_bg(list<L_block *> &bl) {
    RA_bg = Graph<L_block *>();
    block_env.clear();

    // Add nodes to the graph and the block environment
    for (auto block : bl) {
        block_env.insert({block->label, block});
        RA_bg.addNode(block);
    }

    // Add edges based on successors
    for (auto block : bl) {
        for (auto label : block->succs) {
            Enter_bg(block, block_env[label]);
        }
    }

    return RA_bg;
}

// Perform a DFS traversal to mark all reachable nodes
static void DFS(Node<L_block *> *r, Graph<L_block *> &bg) {
    r->color = 1; // Mark the node as visited

    // Recursively visit all unvisited successor nodes
    for (auto succ_num : *r->succ()) {
        auto succ_node = bg.mynodes[succ_num];
        if (succ_node->color != 1) {
            DFS(succ_node, bg);
        }
    }
}

// Perform DFS and remove unreachable blocks from the function's block list
void SingleSourceGraph(Node<L_block *> *r, Graph<L_block *> &bg, L_func *fun) {
    DFS(r, bg);

    int num = 0;
    for (auto block = fun->blocks.begin(); block != fun->blocks.end(); /* increment inside */) {
        if (bg.mynodes[num]->color != 1) {
            block = fun->blocks.erase(block);  // Remove unreachable block
        } else {
            ++block;
        }
        num++;
    }
}

void Show_graph(FILE *out, GRAPH::Graph<LLVMIR::L_block *> &bg) {
    for (auto &block_node : bg.mynodes) {
        auto block = block_node.second->info;
        fprintf(out, "%d\n", block_node.first);
        fprintf(out, "%s \n", block->label->name.c_str());

        // Show predecessors
        fprintf(out, "pred  %zu  ", block_node.second->preds.size());
        for (auto pred : block_node.second->preds) {
            fprintf(out, "%s  ", bg.mynodes[pred]->info->label->name.c_str());
        }
        fprintf(out, "\n");

        // Show successors
        fprintf(out, "succ  %zu  ", block_node.second->succs.size());
        for (auto succ : block_node.second->succs) {
            fprintf(out, "%s  ", bg.mynodes[succ]->info->label->name.c_str());
        }
        fprintf(out, "\n");
    }
}
