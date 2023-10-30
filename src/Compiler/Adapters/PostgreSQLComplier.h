//
// Created by Daniel Byomujuni on 10/27/23.
//

#ifndef NEKODBMS_POSTGRESQLCOMPLIER_H
#define NEKODBMS_POSTGRESQLCOMPLIER_H


#include "AbstractComplier.h"

class PostgreSQLComplier: public AbstractComplier {
protected:
    std::string createDBCommand(Database db) override;
    std::string createTableCommand(Table table) override;
    std::string getColumnType(Column col) override;


public:
    using AbstractComplier::AbstractComplier;
    //using AbstractComplier::getDBCreationCommands;
};


#endif //NEKODBMS_POSTGRESQLCOMPLIER_H
