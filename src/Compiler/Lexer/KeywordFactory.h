//
// Created by Daniel Byomujuni on 11/1/23.
//

#ifndef NEKODBMS_KEYWORDFACTORY_H
#define NEKODBMS_KEYWORDFACTORY_H

#include "Keywords/Abstract/BasicKeyword.h"
#include "Keywords/Types/KeywordBoolean.h"

enum KeywordTypes {
    BooleanKey,
    DependsKey,
    EndKey,
    IntegerKey,
    NullKey,
    PrimaryKey,
    SchemaKey,
    StringKey,
    TableKey,
    LetKey,
    ReturnKey,
    FunctionKey,
    AssignOperation,
    DataOperations
};

class KeywordFactory {
public:
    static BasicKeyword *createKeyword(KeywordTypes type, int line);
    static BasicKeyword *createKeyword(std::string type, int line);
    static KeywordTypes keyToType(std::string key, int line);
};


#endif //NEKODBMS_KEYWORDFACTORY_H
