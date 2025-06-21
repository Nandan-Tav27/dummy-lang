#pragma once

struct ASTNode {
    virtual ~ASTNode() = default;
};

struct IdentNode;
struct NumNode;
struct AsgnOpNode;
struct AddOpNode;
struct SubOpNode;
struct MultOpNode;
struct DivOpNode;
struct LeftParanNode;
struct RightParanNode;
struct SemiColonNode;
struct FactorStmtNode;
struct TermPrmStmtNode;
struct TermStmtNode;
struct ExprPrmStmtNode;
struct ExprStmtNode;
struct AsgnStmtNode;
struct StmtNode;
