//
// Created by Daniel on 11/6/23.
//

#include <sstream>
#include <iostream>
#include "KeywordLet.h"

Token *KeywordLet::lex(int *currentWordIndex, std::vector<std::string> text) {
    std::string name = text.at(*currentWordIndex + 1);
    if (name.ends_with(";")) {
        name.pop_back();
    }
    *currentWordIndex += 1;
    return new Token(Let, {name});
}

