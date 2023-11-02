//
// Created by Daniel Byomujuni on 11/1/23.
//

#include "KeywordFactory.h"
#include "Keywords/KeywordDepends.h"
#include "Keywords/KeywordEnd.h"
#include "Keywords/KeywordInteger.h"
#include "Keywords/KeywordNull.h"
#include "Keywords/KeywordPrimary.h"
#include "Keywords/KeywordSchema.h"
#include "Keywords/KeywordString.h"
#include "Keywords/KeywordTable.h"

#include <map>

BasicKeyword *KeywordFactory::createKeyword(KeywordTypes type) {
    switch (type) {
        case BooleanKey:
            return new KeywordBoolean();
        case DependsKey:
            return new KeywordDepends();
        case EndKey:
            return new KeywordEnd();
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

    std::string subKey = key.substr(0, key.find('('));

    return keywords[subKey];
}

BasicKeyword *KeywordFactory::createKeyword(std::string type) {
    KeywordTypes typeItem = KeywordFactory::keyToType(type);
    return KeywordFactory::createKeyword(typeItem);
}
