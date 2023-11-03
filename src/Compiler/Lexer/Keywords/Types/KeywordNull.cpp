//
// Created by Daniel on 10/31/23.
//

#include "KeywordNull.h"
#include "../Abstract/Observer.h"

Token *KeywordNull::lex(int *currentWordIndex, std::vector<std::string> text) {
    Token *temp = new Token(SetNull, {});

    this->token = temp;
    Observer::getInst()->awaitAttribute(this);
    checkAttribute(currentWordIndex, text);
    return this->token;
}
