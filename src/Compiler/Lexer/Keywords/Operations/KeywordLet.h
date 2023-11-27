//
// Created by Daniel on 11/6/23.
//

#ifndef NEKODBMS_KEYWORDLET_H
#define NEKODBMS_KEYWORDLET_H


#include "../Abstract/BasicKeyword.h"

class KeywordLet : public BasicKeyword {
public:
    Token *lex(int *currentWordIndex, std::vector<std::string> text) override;
};

#endif //NEKODBMS_KEYWORDLET_H
