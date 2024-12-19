#ifndef __SSA
#define __SSA

#include "temp.h"
#include "llvm_ir.h"
#include "graph.hpp"
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <list>

/* Main SSA Function */
LLVMIR::L_prog* SSA(LLVMIR::L_prog* prog);

/* Combine address operands in the function */
void combine_addr(LLVMIR::L_func* fun);

/* Perform memory-to-register optimization in the function */
void mem2reg(LLVMIR::L_func* fun);

/* Compute the dominator sets for the block graph */
void Dominators(GRAPH::Graph<LLVMIR::L_block*>& bg);

/* Compute the dominator tree for the block graph */
void tree_Dominators(GRAPH::Graph<LLVMIR::L_block *> &bg);

/* Compute the dominance frontier for the block graph */
void computeDF(GRAPH::Graph<LLVMIR::L_block *> &bg, GRAPH::Node<LLVMIR::L_block *> *r);

/* Place Phi functions in the block graph */
void Place_phi_fu(GRAPH::Graph<LLVMIR::L_block *> &bg, LLVMIR::L_func *fun);

/* Rename temporary variables in the block graph */
void Rename(GRAPH::Graph<LLVMIR::L_block *> &bg);

/* Print dominators for debugging */
void printf_domi();

/* Print the dominator tree for debugging */
void printf_D_tree();

/* Print the dominance frontier for debugging */
void printf_DF();

#endif
