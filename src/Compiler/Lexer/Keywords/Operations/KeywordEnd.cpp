//
// Created by Daniel on 10/31/23.
//

#include "KeywordEnd.h"

Token *KeywordEnd::lex(int *currentWordIndex, std::vector<std::string> text) {
    return new Token(End,{});
}
