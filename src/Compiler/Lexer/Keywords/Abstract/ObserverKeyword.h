//
// Created by Daniel on 10/30/23.
//

#ifndef NEKODBMS_OBSERVERKEYWORD_H
#define NEKODBMS_OBSERVERKEYWORD_H


#include "BasicKeyword.h"

class ObserverKeyword: public BasicKeyword {
protected:
    void checkAttribute(int *currentWordIndex, std::vector<std::string> text);
public:
    ObserverKeyword() = default;
    virtual void updateAttribute(std::vector<std::string> att) = 0;
    virtual Token *getTokens() = 0;
};


#endif //NEKODBMS_OBSERVERKEYWORD_H
