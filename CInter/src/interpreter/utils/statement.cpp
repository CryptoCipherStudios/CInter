#include "statement.h"

std::shared_ptr<RuntimeValue> evaluateProgram(std::unique_ptr<Program> program, Environment& env)
{
    std::shared_ptr<RuntimeValue> lastEvaluated = MAKE_NULL();

    for (const auto& statement : program->body) {
        lastEvaluated = evaluate(statement, env);  
    }

    return lastEvaluated;
}

std::shared_ptr<RuntimeValue> evaluateVariableDeclaration(VariableDeclaration& declaration, Environment& env) {
	std::shared_ptr<RuntimeValue> value = declaration.value
		? evaluate(std::shared_ptr<Expression>(declaration.value.release()), env)
		: MAKE_NULL();

	return env.declareVariable(declaration.identifier, value, declaration.constant);
}
