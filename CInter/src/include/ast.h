#pragma once

#include <string>
#include <string_view>
#include <vector>
#include <memory>

enum class NodeType {
    Program,
    NumericLiteral,
    Identifier,
    VariableDeclaration,
    BinaryExpression,
    AssignmentExpression,
    ObjectLiteral,
    Property,
    MemberExpression,
    CallExpression
};

struct Statement {
    NodeType kind { };

    virtual ~Statement() noexcept = default;
};

struct Expression : public Statement {
   
};

struct Program : public Statement {
    std::vector<std::shared_ptr<Statement>> body;

    Program() {
        kind = NodeType::Program;
    }

    Program(const Program&) = delete;             
    Program& operator = (const Program&) = delete;   

    Program(Program&&) = default;                  
    Program& operator = (Program&&) = default;      

    ~Program() noexcept override = default;
};

struct _Identifier : public Expression {
    std::string symbol;

    _Identifier(const std::string& sym) : symbol(sym) {
        kind = NodeType::Identifier;
    }
};

struct NumericLiteral : public Expression {
    int value { NULL }; 

    NumericLiteral() {
        kind = NodeType::NumericLiteral;
    }
};

struct VariableDeclaration : public Statement {
    bool constant { false };
    std::string identifier;
    std::unique_ptr<Expression> value;

    VariableDeclaration() {
        kind = NodeType::VariableDeclaration;
    }
};

struct AssignmentExpression : public Expression {
    std::unique_ptr<Expression> assignee;
    std::unique_ptr<Expression> value;

    AssignmentExpression() {
        kind = NodeType::AssignmentExpression;
    }
};

struct BinaryExpression : public Expression {
    std::shared_ptr<Expression> left;
    std::shared_ptr<Expression> right;
    std::string _operator;

    BinaryExpression() {
        kind = NodeType::BinaryExpression;
    }
};

struct Property : public Expression {
    std::string key;
    std::unique_ptr<Expression> value;

    Property() {
        kind = NodeType::Property;
    }
};

struct ObjectLiteral : public Expression {
    std::vector<std::unique_ptr<Property>> properties;

    ObjectLiteral() {
        kind = NodeType::ObjectLiteral;
    }
};

struct MemberExpression : public Expression {
    std::unique_ptr<Expression> object;
    std::unique_ptr<Expression> property;

    bool computed;

    MemberExpression(bool comp) {
        kind = NodeType::MemberExpression;
    }
};

struct CallExpression : public Expression {
    std::vector<std::unique_ptr<Expression>> args;
    std::unique_ptr<Expression> caller;

    CallExpression() {
        kind = NodeType::CallExpression;
    }
};