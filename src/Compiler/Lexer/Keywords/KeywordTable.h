//
// Created by Daniel on 10/30/23.
//

#ifndef NEKODBMS_KEYWORDTABLE_H
#define NEKODBMS_KEYWORDTABLE_H


#include "Abstract/BasicKeyword.h"

class KeywordTable : BasicKeyword {
public:
    Token lex(int *currentWordIndex, std::vector<std::string> text) override;
};


#endif //NEKODBMS_KEYWORDTABLE_H
