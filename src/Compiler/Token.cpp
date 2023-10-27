//
// Created by Daniel on 10/25/23.
//

#include <format>
#include <sstream>
#include <iterator>
#include "Token.h"

Token::Token(TokenType type, std::vector<std::string> value) {
    this->type = type;
    this->value = value;
}

TokenType Token::getType() {
    return this->type;
}

std::vector<std::string> Token::getValue() {
    return this->value;
}

std::string Token::toString() {
    std::stringstream out;
    for (std::string arg: this->value) {
        out << arg << ",";
    }

    std::string result = out.str().substr(0, out.str().length() - 1);

    //result.pop_back();

    return std::format("{0}:{1}", (int) this->type, result);
}
