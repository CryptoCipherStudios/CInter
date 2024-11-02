#pragma once

#include "values.h"
#include "ast.h"
#include "interpreter.h"
#include <memory>

std::shared_ptr<RuntimeValue> evaluateProgram(std::unique_ptr<Program> program);
std::shared_ptr<RuntimeValue> evaluateVariableDeclaration(VariableDeclaration& declaration, Environment& env);