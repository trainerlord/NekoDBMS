//
// Created by Daniel on 10/31/23.
//

#include <stdexcept>
#include "KeywordPrimary.h"
#include "../Abstract/Observer.h"

Token *KeywordPrimary::lex(int *currentWordIndex, std::vector<std::string> text) {
    Token *temp = new Token(SetPrimaryKey, {});

    this->token = temp;
    Observer::getInst()->awaitAttribute(this);
    checkAttribute(currentWordIndex, text);
    return this->token;
}

