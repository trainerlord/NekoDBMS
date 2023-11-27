//
// Created by Daniel on 11/27/23.
//

#ifndef NEKODBMS_DATAOPERATIONS_H
#define NEKODBMS_DATAOPERATIONS_H


#include "../Abstract/BasicKeyword.h"

class DataOperations : public BasicKeyword {
public:
    Token *lex(int *currentWordIndex, std::vector<std::string> text) override;
};




#endif //NEKODBMS_DATAOPERATIONS_H
