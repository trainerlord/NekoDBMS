//
// Created by Daniel on 10/31/23.
//

#include "KeywordBoolean.h"
#include "Abstract/Observer.h"

Token *KeywordBoolean::lex(int *currentWordIndex, std::vector<std::string> text) {
    Token *temp = new Token(Boolean, {});

    this->token = temp;
    Observer::getInst()->awaitAttribute(this);
    checkAttribute(currentWordIndex, text);
    return this->token;
}
