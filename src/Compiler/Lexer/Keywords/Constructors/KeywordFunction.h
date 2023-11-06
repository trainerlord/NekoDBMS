//
// Created by Daniel on 11/6/23.
//

#ifndef NEKODBMS_KEYWORDFUNCTION_H
#define NEKODBMS_KEYWORDFUNCTION_H


#include "../../../Token.h"
#include "../Abstract/BasicKeyword.h"

class KeywordFunction : public BasicKeyword {
public:
    Token *lex(int *currentWordIndex, std::vector<std::string> text) override;
};


#endif //NEKODBMS_KEYWORDFUNCTION_H
