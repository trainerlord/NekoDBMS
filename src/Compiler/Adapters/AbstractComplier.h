//
// Created by Daniel Byomujuni on 10/27/23.
//

#ifndef NEKODBMS_ABSTRACTCOMPLIER_H
#define NEKODBMS_ABSTRACTCOMPLIER_H


#include <utility>

#include "../Paser.h"

class AbstractComplier {
protected:
    ParsedSource src;

    virtual std::string createDBCommand(Database db) {return "";};
    virtual std::string createTableCommand(Table table) {return "";};
    virtual std::string getColumnType(Column col) {return "";};


public:
    explicit AbstractComplier(ParsedSource src) {this->src = std::move(src);}
    std::vector<std::string> getDBCreationCommands();
};


#endif //NEKODBMS_ABSTRACTCOMPLIER_H
