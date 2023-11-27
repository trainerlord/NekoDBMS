//
// Created by Daniel on 11/27/23.
//

#include "DataOperations.h"
#include "DataOperations/OperationSelect.h"
#include "DataOperations/OperationJoin.h"

Token *DataOperations::lex(int *currentWordIndex, std::vector<std::string> text) {

    *currentWordIndex += 1;

    if (text.at(*currentWordIndex).starts_with("select")) {
        return OperationSelect().lex(currentWordIndex, text);
    }
    if (text.at(*currentWordIndex).starts_with("join")) {
        return OperationJoin().lex(currentWordIndex, text);
    }

    return nullptr;
}