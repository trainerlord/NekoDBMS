//
// Created by Daniel on 11/27/23.
//

#ifndef NEKODBMS_OPERATIONASSIGN_H
#define NEKODBMS_OPERATIONASSIGN_H

#include "../Abstract/BasicKeyword.h"

class OperationAssign : public BasicKeyword {
public:
    Token *lex(int *currentWordIndex, std::vector<std::string> text) override;
};



#endif //NEKODBMS_OPERATIONASSIGN_H
