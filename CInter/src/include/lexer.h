#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <unordered_map>

enum TokenType {
	Number, // 0
	Identifier, // 1
	Let, // 2
	Const, // 3
	Exostatic, // 4
	Static, // 5
	BinaryOperator, // 6
	Equals, // 7
	Comma, // 8
	Colon, // 9
	Semicolon, // 10
	OpenParen, // 11
	CloseParen, // 12
	OpenBrace, // 13
	CloseBrace, // 14
	OpenBracket, // 15
	CloseBracket, // 16
	Dot, // 17
	_EOF, // 18
};

const std::unordered_map<std::string, TokenType> KEYWORDS {
	{ "let", TokenType::Let },
	{ "const", TokenType::Const },
	{ "exostatic", TokenType::Exostatic },
	{ "static", TokenType::Static }
};

struct Token {
	std::string value;
	TokenType type;
};

Token createToken(const std::string& value, TokenType type);

bool isAlphabetic(const std::string& source);
bool isSkippable(char ch);
bool isInteger(char ch);

std::vector<Token> Tokenize(const std::string& sourceCode);
