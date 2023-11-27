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
#include "Keywords/Operations/KeywordReturn.h"
#include "Keywords/Operations/KeywordLet.h"
#include "Keywords/Constructors/KeywordFunction.h"
#include "Keywords/Operations/OperationAssign.h"
#include "Keywords/Operations/DataOperations.h"

#include <map>
#include <iostream>

BasicKeyword *KeywordFactory::createKeyword(KeywordTypes type, int line) {
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
        case LetKey:
            return new KeywordLet();
        case ReturnKey:
            return new KeywordReturn();
        case FunctionKey:
            return new KeywordFunction();
        case AssignOperation:
            return new OperationAssign();
        case DataOperations:
            return new class DataOperations();
        default:
            return new KeywordEnd();
    }
}

KeywordTypes KeywordFactory::keyToType(std::string key, int line) {
    std::map<std::string, KeywordTypes> keywords;

    keywords["@Schema"] = SchemaKey;
    keywords["@Table"] = TableKey;
    keywords["@Primary"] = PrimaryKey;
    keywords["@String"] = StringKey;
    keywords["@Integer"] = IntegerKey;
    keywords["@Boolean"] = BooleanKey;
    keywords["@Depends"] = DependsKey;
    keywords["@Null"] = NullKey;
    keywords["@return"] = ReturnKey;
    keywords["@let"] = LetKey;
    keywords["@Function"] = FunctionKey;

    keywords["."] = DataOperations;

    keywords["="] = AssignOperation;
    keywords["}"] = EndKey;
    keywords["{}"] = EndKey;


    std::string subKey = key.substr(0, key.find('('));

    if (keywords.contains(subKey)) {
        return keywords[subKey];
    }
    throw new std::exception();
}

BasicKeyword *KeywordFactory::createKeyword(std::string type, int line) {
    KeywordTypes typeItem = KeywordFactory::keyToType(type, line);
    return KeywordFactory::createKeyword(typeItem, line);
}
