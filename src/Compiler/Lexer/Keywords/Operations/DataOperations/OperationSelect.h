//
// Created by Daniel on 11/27/23.
//

#ifndef NEKODBMS_OPERATIONSELECT_H
#define NEKODBMS_OPERATIONSELECT_H

#include "../../Abstract/BasicKeyword.h"

class OperationSelect : public BasicKeyword {
public:
    Token *lex(int *currentWordIndex, std::vector<std::string> text) override;
};
#endif //NEKODBMS_OPERATIONSELECT_H
