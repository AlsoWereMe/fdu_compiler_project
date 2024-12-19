#ifndef __LIVENESS
#define __LIVENESS

#include <list>
#include <unordered_map>
#include <unordered_set>
#include "graph.hpp"
#include "llvm_ir.h"
#include "temp.h"

// Function to perform liveness analysis on the graph
void Liveness(GRAPH::Node<LLVMIR::L_block*>* r, GRAPH::Graph<LLVMIR::L_block*>& bg, std::vector<Temp_temp*>& args);

// Function to display liveness information
void Show_Liveness(FILE* out, GRAPH::Graph<LLVMIR::L_block*>& bg);

// Get the "out" set of temporary variables for a block
TempSet_& FG_Out(GRAPH::Node<LLVMIR::L_block*>* r);

// Get the "in" set of temporary variables for a block
TempSet_& FG_In(GRAPH::Node<LLVMIR::L_block*>* r);

// Get the "def" set (variables defined) for a block
TempSet_& FG_def(GRAPH::Node<LLVMIR::L_block*>* r);

// Get the "use" set (variables used) for a block
TempSet_& FG_use(GRAPH::Node<LLVMIR::L_block*>* r);

// Get all operands used in a statement (for liveness analysis)
std::list<AS_operand**> get_all_AS_operand(LLVMIR::L_stm* stm);

// Get the def operands in a statement (variables assigned)
std::list<AS_operand**> get_def_operand(LLVMIR::L_stm* stm);

// Get the def temporary variables in a statement
std::list<Temp_temp*> get_def(LLVMIR::L_stm* stm);

// Get the use operands in a statement (variables used)
std::list<AS_operand**> get_use_operand(LLVMIR::L_stm* stm);

// Get the use temporary variables in a statement
std::list<Temp_temp*> get_use(LLVMIR::L_stm* stm);

#endif
