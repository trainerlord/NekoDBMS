//
// Created by Daniel on 11/27/23.
//

#include <sstream>
#include "OperationAssign.h"

Token *OperationAssign::lex(int *currentWordIndex, std::vector<std::string> text) {

    auto *toke = new Token(Assign, {text.at(*currentWordIndex - 1)});
    *currentWordIndex += 1;
    return toke;
}
