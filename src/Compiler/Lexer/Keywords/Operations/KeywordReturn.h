//
// Created by Daniel on 11/6/23.
//

#ifndef NEKODBMS_KEYWORDRETURN_H
#define NEKODBMS_KEYWORDRETURN_H


#include "../Abstract/BasicKeyword.h"

class KeywordReturn : public BasicKeyword {
public:
    Token *lex(int *currentWordIndex, std::vector<std::string> text) override;

};

#endif //NEKODBMS_KEYWORDRETURN_H
