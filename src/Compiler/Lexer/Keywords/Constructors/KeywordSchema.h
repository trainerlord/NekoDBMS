//
// Created by Daniel on 10/30/23.
//

#ifndef NEKODBMS_KEYWORDSCHEMA_H
#define NEKODBMS_KEYWORDSCHEMA_H


#include "../Abstract/BasicKeyword.h"

class KeywordSchema : public BasicKeyword {
public:
    Token *lex(int *currentWordIndex, std::vector<std::string> text) override;
};


#endif //NEKODBMS_KEYWORDSCHEMA_H
