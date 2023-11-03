//
// Created by Daniel Byomujuni on 11/1/23.
//

#include "KeywordFactory.h"
#include "Keywords/Operations/KeywordDepends.h"
#include "Keywords/Operations/KeywordEnd.h"
#include "Keywords/Types/KeywordInteger.h"
#include "Keywords/Types/KeywordNull.h"
#include "Keywords/Types/KeywordPrimary.h"
#include "Keywords/Constructors/KeywordSchema.h"
#include "Keywords/Types/KeywordString.h"
#include "Keywords/Constructors/KeywordTable.h"

#include <map>
#include <iostream>

BasicKeyword *KeywordFactory::createKeyword(KeywordTypes type) {
    switch (type) {
        case BooleanKey:
            return new KeywordBoolean();
        case DependsKey:
            return new KeywordDepends();
        case IntegerKey:
            return new KeywordInteger();
        case NullKey:
            return new KeywordNull();
        case PrimaryKey:
            return new KeywordPrimary();
        case SchemaKey:
            return new KeywordSchema();
        case StringKey:
            return new KeywordString();
        case TableKey:
            return new KeywordTable();
        default:
            return new KeywordEnd();
    }
}

KeywordTypes KeywordFactory::keyToType(std::string key) {
    std::map<std::string, KeywordTypes> keywords;

    keywords["@Schema"] = SchemaKey;
    keywords["@Table"] = TableKey;
    keywords["@Primary"] = PrimaryKey;
    keywords["@String"] = StringKey;
    keywords["@Integer"] = IntegerKey;
    keywords["@Boolean"] = BooleanKey;
    keywords["@Depends"] = DependsKey;
    keywords["@Null"] = NullKey;
    keywords["}"] = EndKey;
    keywords["{}"] = EndKey;


    std::string subKey = key.substr(0, key.find('('));

    try {
        return keywords[subKey];
    } catch (int myNum) {
        std::cout << "Invild Keyword" << subKey << std::endl;
        exit(0);
    }
}

BasicKeyword *KeywordFactory::createKeyword(std::string type) {
    KeywordTypes typeItem = KeywordFactory::keyToType(type);
    return KeywordFactory::createKeyword(typeItem);
}
