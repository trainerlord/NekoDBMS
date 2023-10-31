//
// Created by Daniel on 10/30/23.
//

#include <stdexcept>
#include <iostream>
#include "KeywordSchema.h"

Token *KeywordSchema::lex(int *currentWordIndex, std::vector<std::string> text) {
    std::cout << "test" << std::endl;
    if (text.at(*currentWordIndex + 1) == "{" && text.at(*currentWordIndex + 2) != "{") {
        //Source Code Format Error
        throw std::invalid_argument("Invaild Source Code");
    }
    Token *temporayToken = new Token(CreateDatabase,{text.at(*currentWordIndex + 1)});
    *currentWordIndex += 2;
    return temporayToken;
}
