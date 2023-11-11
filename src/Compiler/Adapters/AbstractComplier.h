//
// Created by Daniel Byomujuni on 10/27/23.
//

#ifndef NEKODBMS_ABSTRACTCOMPLIER_H
#define NEKODBMS_ABSTRACTCOMPLIER_H


#include <utility>

#include "../Parser.h"
#include "SchemaInstructions.h"

class AbstractComplier {
protected:
    ParsedSource src;

    virtual std::string createDBCommand(Database db) {return "";};
    virtual std::string createTableCommand(std::string parent, Table table) {return "";};
    virtual std::string createFunctionCommand(std::string parent, Functions func) {return "";};
    virtual std::string getColumnType(Column col) {return "";};


public:
    explicit AbstractComplier(ParsedSource src) {this->src = std::move(src);}
    SchemaInstructions getDBCreationCommands();
};


#endif //NEKODBMS_ABSTRACTCOMPLIER_H
