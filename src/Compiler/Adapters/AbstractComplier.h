//
// Created by Daniel Byomujuni on 10/27/23.
//

#ifndef NEKODBMS_ABSTRACTCOMPLIER_H
#define NEKODBMS_ABSTRACTCOMPLIER_H


#include "../Paser.h"

class AbstractComplier {
    ParsedSource src;
    virtual std::string createDBCommand(Database db);
    virtual std::string createTableCommand(Table table);

    virtual std::string getColumnType(Column col);


public:
    AbstractComplier(ParsedSource src);
    std::vector<std::string> getDBCreationCommands();
};


#endif //NEKODBMS_ABSTRACTCOMPLIER_H
