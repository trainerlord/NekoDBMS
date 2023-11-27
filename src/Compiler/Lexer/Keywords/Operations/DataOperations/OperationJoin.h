//
// Created by Daniel on 11/27/23.
//

#ifndef NEKODBMS_OPERATIONJOIN_H
#define NEKODBMS_OPERATIONJOIN_H

#include "../../Abstract/BasicKeyword.h"

class OperationJoin : public BasicKeyword {
public:
    Token *lex(int *currentWordIndex, std::vector<std::string> text) override;
};

#endif //NEKODBMS_OPERATIONJOIN_H
