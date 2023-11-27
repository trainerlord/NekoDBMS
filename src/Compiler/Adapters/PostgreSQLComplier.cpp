//
// Created by Daniel Byomujuni on 10/27/23.
//
#include <format>
#include <sstream>

#include "PostgreSQLComplier.h"


std::string PostgreSQLComplier::createTableCommand(std::string parent, Table table) {
    std::stringstream cmd;
    cmd << std::format(R"(CREATE TABLE "{}"."{}" ()", parent,table.name);
    for (Column col : table.columns) {
        cmd << std::format("\"{}\" {}{}, ", col.name, this->getColumnType(col), (col.optional ? " NOT NULL" : ""));
    }

    cmd << " PRIMARY KEY (";
    for (std::string keys : table.primaryKey) {
        cmd << keys << ", ";
    }
    cmd.seekp(-2, std::ios_base::end);

    if (!table.constraints.empty()) {
        for(auto it = table.constraints.begin(); it != table.constraints.end(); ++it) {
            cmd << std::format("), CONSTRAINT {} ", it->first);
            //?
            cmd << " FOREIGN KEY(";
            for (std::string localKey : table.constraints.at(it->first).localKeys) {
                cmd << localKey << ", ";
            }
            cmd.seekp(-2, std::ios_base::end);
            cmd << ") ";

            cmd << "REFERENCES ";

            std::string currentTable = "";

            for (std::string foriengkey : table.constraints.at(it->first).foreignKeys) {
                if (currentTable == "") {
                    currentTable = foriengkey.substr(0, foriengkey.find('.'));
                    cmd << "\"" << currentTable << "\"" << " (" << foriengkey.substr(foriengkey.find('.') + 1,foriengkey.length());
                    continue;
                }

                if (currentTable == foriengkey.substr(0, foriengkey.find('.'))) {
                    cmd << " ," << foriengkey.substr(foriengkey.find('.')+ 1,foriengkey.length());
                } else {
                    //throw error;
                }
            }
        }
    }
    cmd << "));";
    return cmd.str();
}

std::string PostgreSQLComplier::getColumnType(Column col) {
    switch (col.type) {
        case STRING:
            return "TEXT";
        case INTEGER:
            return "INT";
        case BOOLEAN:
            return "BOOLEAN";
        default:
            //throw error
            return "INT";
    }
}

std::string PostgreSQLComplier::createDBCommand(Database db)  {
    std::string cmd = std::format(R"(CREATE DATABASE "{0}";)", db.name);
    return cmd;
}

std::string PostgreSQLComplier::createFunctionCommand(std::string parent, Functions func) {

    //func.name

    //parse the map of params

    //translate the return vaule

    //Sub any vars with translated operations
    
    /*
        CREATE PROCEDURE ${name}(${params})
        LANGUAGE SQL
        BEGIN ATOMIC
          ${queryies}
        END;`

     */



    return AbstractComplier::createFunctionCommand(parent, func);
}
