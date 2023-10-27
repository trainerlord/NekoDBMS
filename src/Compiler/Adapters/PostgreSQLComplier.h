//
// Created by Daniel Byomujuni on 10/27/23.
//

#ifndef NEKODBMS_POSTGRESQLCOMPLIER_H
#define NEKODBMS_POSTGRESQLCOMPLIER_H


#include "AbstractComplier.h"

class PostgreSQLComplier: AbstractComplier {
    std::string createDBCommand(Database db) override;
    std::string createTableCommand(Table table) override;

    std::string getColumnType(Column col) override;
};


#endif //NEKODBMS_POSTGRESQLCOMPLIER_H
