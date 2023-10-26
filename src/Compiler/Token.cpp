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
    std::ostringstream out;
    if (!this->value.empty())
    {
        std::copy(std::begin(this->value), std::end(this->value) - 1, std::ostream_iterator<std::string>(out, ","));
        out << this->value.back();
    }
    return std::format("{0}:{1}", (int) this->type, out.str());
}
