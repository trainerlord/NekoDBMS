//
// Created by Daniel on 10/31/23.
//

#ifndef NEKODBMS_KEYWORDEND_H
#define NEKODBMS_KEYWORDEND_H


#include "../../Token.h"
#include "Abstract/BasicKeyword.h"

class KeywordEnd : public BasicKeyword {
public:
    Token *lex(int *currentWordIndex, std::vector<std::string> text) override;

};


#endif //NEKODBMS_KEYWORDEND_H
