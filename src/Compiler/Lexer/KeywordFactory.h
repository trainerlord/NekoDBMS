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
    TableKey
};

class KeywordFactory {
public:
    static BasicKeyword *createKeyword(KeywordTypes type);
    static BasicKeyword *createKeyword(std::string type);
    static KeywordTypes keyToType(std::string key);
};


#endif //NEKODBMS_KEYWORDFACTORY_H
