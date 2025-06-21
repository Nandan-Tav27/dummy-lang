#include "ASTNode.h"
#include "Token.h"

struct IdentNode : ASTNode {
    Token identifierToken;

    explicit IdentNode(Token token) {
        if (token.type != identifier)
            throw std::invalid_argument("expected identifier token");
        if (!token.value.has_value())
            throw std::invalid_argument("value expected for identifier");

        identifierToken = token;
    }
};

struct NumNode : ASTNode {
    Token numberToken;

    explicit NumNode(Token token) {
        if (token.type != number)
            throw std::invalid_argument("expected number token");
        if (!token.value.has_value())
            throw std::invalid_argument("value expected for number");

        numberToken = token;
    }
};

struct AsgnOpNode : ASTNode {
    Token assignmentToken;

    explicit AsgnOpNode(Token token) {
        if (token.type != assignment_operator)
            throw std::invalid_argument("expected assignment operator token");

        assignmentToken = token;
    }
};

struct AddOpNode : ASTNode {
    Token additionToken;

    explicit AddOpNode(Token token) {
        if (token.type != addition_operator)
            throw std::invalid_argument("expected addition operator token");

        additionToken = token;
    }
};

struct SubOpNode : ASTNode {
    Token subtractionToken;

    explicit SubOpNode(Token token) {
        if (token.type != subtraction_operator)
            throw std::invalid_argument("expected subtraction operator token");

        subtractionToken = token;
    }
};

struct MultOpNode : ASTNode {
    Token multiplicationToken;

    explicit MultOpNode(Token token) {
        if (token.type != multiplication_operator)
            throw std::invalid_argument("expected multiplication operator token");

        multiplicationToken = token;
    }
};

struct DivOpNode : ASTNode {
    Token divisionToken;

    explicit DivOpNode(Token token) {
        if (token.type != division_operator)
            throw std::invalid_argument("expected division operator token");

        divisionToken = token;
    }
};

struct LeftParanNode : ASTNode {
    Token leftParenthesis;

    explicit LeftParanNode(Token token) {
        if (token.type != left_parenthesis)
            throw std::invalid_argument("expected left parenthesis token");

        leftParenthesis = token;
    }
};

struct RightParanNode : ASTNode {
    Token rightParenthesis;

    explicit RightParanNode(Token token) {
        if (token.type != right_parenthesis)
            throw std::invalid_argument("expected right parenthesis token");

        rightParenthesis = token;
    }
};

struct SemiColonNode : ASTNode {
    Token semiColonToken;

    explicit SemiColonNode(Token token) {
        if (token.type != semicolon)
            throw std::invalid_argument("expected semicolon token");

        semiColonToken = token;
    }
};

struct FactorStmtNode : ASTNode {
    std::optional<std::unique_ptr<IdentNode>> identifierPtr;
    std::optional<std::unique_ptr<NumNode>> numberPtr;
    std::optional<std::unique_ptr<LeftParanNode>> leftParenthesisPtr;
    std::optional<std::unique_ptr<ExprStmtNode>> expressionStatementPtr;
    std::optional<std::unique_ptr<RightParanNode>> rightParenthesisPtr;
};

struct TermPrmStmtNode : ASTNode {
    std::optional<std::unique_ptr<MultOpNode>> multiplicationOperatorPtr;
    std::optional<std::unique_ptr<DivOpNode>> divisionOperatorPtr;
    std::optional<std::unique_ptr<FactorStmtNode>> factorStatementPtr;
    std::optional<std::unique_ptr<TermPrmStmtNode>> termPrimeStatementPtr;
};

struct TermStmtNode : ASTNode {
    std::optional<std::unique_ptr<FactorStmtNode>> factorStatementPtr;
    std::optional<std::unique_ptr<TermPrmStmtNode>> termPrimeStatementPtr;
};

struct ExprPrmStmtNode : ASTNode {
    std::optional<std::unique_ptr<AddOpNode>> additionOperatorPtr;
    std::optional<std::unique_ptr<SubOpNode>> subtractionOperatorPtr;
    std::optional<std::unique_ptr<TermStmtNode>> termStatementPtr;
    std::optional<std::unique_ptr<ExprPrmStmtNode>> expressionPrimeStatementPtr;
};

struct ExprStmtNode : ASTNode {
    std::unique_ptr<TermStmtNode> termStatementPtr;
    std::unique_ptr<ExprPrmStmtNode> expressionPrimeStatementPtr;
};

struct AsgnStmtNode : ASTNode {
    std::unique_ptr<IdentNode> identifierPtr;
    std::unique_ptr<AsgnOpNode> assignmentOperatorPtr;
    std::unique_ptr<ExprStmtNode> expressionStatementPtr;
};

struct StmtNode : ASTNode {
    std::optional<std::unique_ptr<AsgnStmtNode>> assignmentStatementPtr;
    std::optional<std::unique_ptr<ExprStmtNode>> expressionStatementPtr;
};
