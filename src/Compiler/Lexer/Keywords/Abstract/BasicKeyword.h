//
// Created by Daniel on 10/30/23.
//

#ifndef NEKODBMS_BASICKEYWORD_H
#define NEKODBMS_BASICKEYWORD_H


#include <string>
#include "../../../Token.h"

class BasicKeyword {
public:
    virtual Token *lex(int *currentWordIndex, std::vector<std::string> text) = 0;
};


#endif //NEKODBMS_BASICKEYWORD_H
