//
// Created by Daniel Byomujuni on 10/27/23.
//
#include <format>
#include <sstream>

#include "PostgreSQLComplier.h"

std::string PostgreSQLComplier::createDBCommand(Database db) {
    std::string cmd = std::format("CREATE DATABASE {};", db.name);
    return cmd;
}

std::string PostgreSQLComplier::createTableCommand(Table table) {
    std::stringstream cmd;
    cmd << std::format("CREATE TABLE {} (", table.name);
    for (Column col : table.columns) {
        cmd << std::format(" \"{}\" {} {},", col.name, this->getColumnType(col), (col.optional ? "NOT NULL" : ""));
    }

    cmd << " PRIMARY KEY (";
    for (std::string keys : table.primaryKey) {
        cmd << keys << ", ";
    }
    cmd.seekp(-2, std::ios_base::end);


    if (!table.constraints.empty()) {
        for(std::map<std::string,std::vector<std::string>>::iterator it = table.constraints.begin(); it != table.constraints.end(); ++it) {
            cmd << std::format(" CONSTRAINT {} ", it->first);

            cmd << " FOREIGN KEY({";
            for (std::string localKey : table.constraints.at(it->first).localKeys) {
                cmd << localKey << ", ";
            }
            cmd.seekp(-2, std::ios_base::end);
            cmd << ")";

            //TODO Write Refrences
            /* REFERENCES table(col1,col2)*/

        }
    }

}

std::string PostgreSQLComplier::getColumnType(Column col) {
    switch (col.type) {
        case UNDEFINED:
            //throw error
            return "INT";
        case STRING:
            return "TEXT";
        case INTEGER:
            return "INT";
        case BOOLEAN:
            return "BOOLEAN";
    }
}
