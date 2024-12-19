#ifndef __AST2LLVM
#define __AST2LLVM

#include "temp.h"
#include "llvm_ir.h"
#include "TeaplaAst.h"
#include <vector>
#include <string>
#include <unordered_map>
#include <list>

// Struct to hold member information in a struct type
struct MemberInfo {
    int offset;        // Offset of the member in the struct
    TempDef def;       // Temporary variable definition for the member

    // Constructor for initializing member information
    MemberInfo(int off = 0, TempDef d = TempDef()) : offset(off), def(d) {}
};

// Struct to hold information about a struct type
struct StructInfo {
    std::unordered_map<std::string, MemberInfo> memberinfos; // Member information for each member of the struct
};

// Struct to hold information about a function
struct Func_local {
    std::string name;              // Function name
    LLVMIR::FuncType ret;          // Return type of the function
    std::vector<Temp_temp *> args; // Arguments to the function
    std::list<LLVMIR::L_stm *> irs; // List of intermediate representations (IR) for the function

    // Constructor for initializing function information
    Func_local(const std::string _name, LLVMIR::FuncType _ret, const std::vector<Temp_temp *> &_args, const std::list<LLVMIR::L_stm *> &_irs)
        : name(_name), ret(_ret), args(_args), irs(_irs) {}
};

// Function declarations for AST to LLVM conversion

// Convert the program from AST to LLVM representation (first pass)
std::vector<LLVMIR::L_def *> ast2llvmProg_first(aA_program p);

// Convert the program from AST to LLVM representation (second pass)
std::vector<Func_local *> ast2llvmProg_second(aA_program p);

// Convert function definition from AST to LLVM
Func_local *ast2llvmFunc(aA_fnDef f);

// Convert a code block statement from AST to LLVM
void ast2llvmBlock(aA_codeBlockStmt b, Temp_label *con_label = nullptr, Temp_label *bre_label = nullptr);

// Convert right-hand side value expression from AST to LLVM
AS_operand *ast2llvmRightVal(aA_rightVal r);

// Convert left-hand side value expression from AST to LLVM
AS_operand *ast2llvmLeftVal(aA_leftVal l);

// Convert index expression from AST to LLVM
AS_operand *ast2llvmIndexExpr(aA_indexExpr index);

// Convert boolean expression from AST to LLVM
AS_operand *ast2llvmBoolExpr(aA_boolExpr b, Temp_label *true_label = nullptr, Temp_label *false_label = nullptr);

// Convert boolean binary operator expression from AST to LLVM
void ast2llvmBoolBiOpExpr(aA_boolBiOpExpr b, Temp_label *true_label, Temp_label *false_label);

// Convert boolean unary operator expression from AST to LLVM
void ast2llvmBoolUOpExpr(aA_boolUOpExpr b, Temp_label *true_label, Temp_label *false_label);

// Convert boolean unit expression from AST to LLVM
void ast2llvmBoolUnit(aA_boolUnit b, Temp_label *true_label, Temp_label *false_label);

// Convert comparison operator expression from AST to LLVM
void ast2llvmComOpExpr(aA_comExpr c, Temp_label *true_label, Temp_label *false_label);

// Convert arithmetic binary operator expression from AST to LLVM
AS_operand *ast2llvmArithBiOpExpr(aA_arithBiOpExpr a);

// Convert arithmetic unary operator expression from AST to LLVM
AS_operand *ast2llvmArithUExpr(aA_arithUExpr a);

// Convert arithmetic expression from AST to LLVM
AS_operand *ast2llvmArithExpr(aA_arithExpr a);

// Convert expression unit from AST to LLVM
AS_operand *ast2llvmExprUnit(aA_exprUnit e);

// Convert the entire program from AST to LLVM
LLVMIR::L_prog *ast2llvm(aA_program p);

// Convert a function block from AST to LLVM
LLVMIR::L_func *ast2llvmFuncBlock(Func_local *f);

// Convert alloca statements in a function to LLVM
void ast2llvm_moveAlloca(LLVMIR::L_func *f);

// First pass for converting right-hand side value to LLVM
int ast2llvmRightVal_first(aA_rightVal r);

// First pass for converting boolean expression to LLVM
int ast2llvmBoolExpr_first(aA_boolExpr b);

// First pass for converting boolean binary operator expression to LLVM
int ast2llvmBoolBiOpExpr_first(aA_boolBiOpExpr b);

// First pass for converting boolean unary operator expression to LLVM
int ast2llvmBoolUOpExpr_first(aA_boolUOpExpr b);

// First pass for converting boolean unit expression to LLVM
int ast2llvmBoolUnit_first(aA_boolUnit b);

// First pass for converting comparison operator expression to LLVM
int ast2llvmComOpExpr_first(aA_comExpr c);

// First pass for converting arithmetic binary operator expression to LLVM
int ast2llvmArithBiOpExpr_first(aA_arithBiOpExpr a);

// First pass for converting arithmetic unary operator expression to LLVM
int ast2llvmArithUExpr_first(aA_arithUExpr a);

// First pass for converting arithmetic expression to LLVM
int ast2llvmArithExpr_first(aA_arithExpr a);

// First pass for converting expression unit to LLVM
int ast2llvmExprUnit_first(aA_exprUnit e);

#endif
