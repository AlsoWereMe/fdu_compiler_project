#ifndef __BG_LLVM
#define __BG_LLVM

#include <unordered_map>
#include "graph.hpp"
#include "llvm_ir.h"
#include "temp.h"

/* Block Graph */

/* Create a block graph from a list of blocks */
GRAPH::Graph<LLVMIR::L_block *> &Create_bg(std::list<LLVMIR::L_block *> &bl);

/* Get the block graph */
GRAPH::Graph<LLVMIR::L_block *> &Bg_graph();

/* Get the block environment map */
std::unordered_map<Temp_label *, LLVMIR::L_block *> &Bg_block_env();

/* Perform Single Source Shortest Path (SSSP) on the block graph */
void SingleSourceGraph(GRAPH::Node<LLVMIR::L_block *> *r, GRAPH::Graph<LLVMIR::L_block *> &bg, LLVMIR::L_func *fun);

/* Display the block graph */
void Show_graph(FILE *out, GRAPH::Graph<LLVMIR::L_block *> &bg);

#endif
