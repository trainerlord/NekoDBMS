//
// Created by Daniel on 10/31/23.
//

#include "KeywordString.h"
#include "Abstract/Observer.h"

Token *KeywordString::lex(int *currentWordIndex, std::vector<std::string> text) {
    Token *temp = new Token(String, {});

    this->token = temp;
    Observer::getInst()->awaitAttribute(this);
    checkAttribute(currentWordIndex, text);
    return this->token;
}
