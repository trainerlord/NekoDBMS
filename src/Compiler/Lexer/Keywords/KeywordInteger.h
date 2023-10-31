//
// Created by Daniel on 10/31/23.
//

#ifndef NEKODBMS_KEYWORDINTEGER_H
#define NEKODBMS_KEYWORDINTEGER_H


#include "Abstract/ObserverKeyword.h"

class KeywordInteger : ObserverKeyword {
private:
    Token *token;
public:
    Token *lex(int *currentWordIndex, std::vector<std::string> text);
    void updateAttribute(std::vector<std::string> att) override {this->token->setValue(att);}
    Token *getTokens() override {return this->token;};
};


#endif //NEKODBMS_KEYWORDINTEGER_H
