//
// Created by Daniel on 10/31/23.
//

#ifndef NEKODBMS_KEYWORDDEPENDS_H
#define NEKODBMS_KEYWORDDEPENDS_H


#include "../Abstract/ObserverKeyword.h"

class KeywordDepends : public ObserverKeyword {
private:
    Token *token;
public:
    Token *lex(int *currentWordIndex, std::vector<std::string> text) override;
    void updateAttribute(std::vector<std::string> att) override;
    Token *getTokens() override {return this->token;};
};



#endif //NEKODBMS_KEYWORDDEPENDS_H
