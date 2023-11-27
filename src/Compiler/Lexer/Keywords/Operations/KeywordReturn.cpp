//
// Created by Daniel on 11/6/23.
//

#include <sstream>
#include "KeywordReturn.h"

Token *KeywordReturn::lex(int *currentWordIndex, std::vector<std::string> text) {
    return new Token(Return, {});
}
