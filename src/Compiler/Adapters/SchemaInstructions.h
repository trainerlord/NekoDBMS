//
// Created by Daniel Byomujuni on 11/2/23.
//

#ifndef NEKODBMS_SCHEMAINSTRUCTIONS_H
#define NEKODBMS_SCHEMAINSTRUCTIONS_H

#include<string>
#include<vector>
#include<map>

struct DatabaseInstructions {
    std::string databaseName;
    std::vector<std::string> tables;
    std::vector<std::string> functions;
};

struct SchemaInstructions {
    std::vector<std::string> root;
    std::map<std::string, DatabaseInstructions> databases;
};
#endif //NEKODBMS_SCHEMAINSTRUCTIONS_H
