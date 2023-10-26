//
// Created by Daniel on 10/25/23.
//

#include <format>
#include "Token.h"

Token::Token(TokenType type, std::string value) {
    this->type = type;
    this->value = value;
}

TokenType Token::getType() {
    return this->type;
}

std::string Token::getValue() {
    return this->value;
}

std::string Token::toString() {


    return std::format("{0}:{1}", (int) this->type, this->value);
}
