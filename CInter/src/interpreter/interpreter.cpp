#include "interpreter.h"

std::shared_ptr<RuntimeValue> evaluate(const std::shared_ptr<Statement>& astNode, Environment& env)
{
	switch (astNode->kind)
	{
		case NodeType::NumericLiteral:
		{
			auto numericLiteral = std::dynamic_pointer_cast<NumericLiteral>(astNode);
			return std::make_shared<NumberValue>(numericLiteral->value);
		}

		case NodeType::BinaryExpression:
		{
			auto binaryExpression = std::dynamic_pointer_cast<BinaryExpression>(astNode);
			return evaluateBinaryExpression(*binaryExpression, env);
		}
		
		case NodeType::Identifier:
		{
			auto ident = std::dynamic_pointer_cast<_Identifier>(astNode);
		}

		
		case NodeType::Program:
		{
			auto program = std::dynamic_pointer_cast<Program>(astNode);
		}

		case NodeType::ObjectLiteral:
		{
			auto obj = std::dynamic_pointer_cast<ObjectLiteral>(astNode);
		}

		case NodeType::VariableDeclaration:
		{
			auto var = std::dynamic_pointer_cast<VariableDeclaration>(astNode);
		}

		case NodeType::CallExpression:
		{
			auto callExpr = std::dynamic_pointer_cast<CallExpression>(astNode);
		}

		case NodeType::AssignmentExpression:
		{
			auto assignExpr = std::dynamic_pointer_cast<AssignmentExpression>(astNode);
		}

		default:
			std::cerr << "This AST Node has not yet been setup for interpretation. ";
			exit(0);
	}

	return nullptr;
}