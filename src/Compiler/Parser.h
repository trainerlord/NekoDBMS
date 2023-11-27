//
// Created by Daniel on 10/26/23.
//

#ifndef NEKODBMS_PARSER_H
#define NEKODBMS_PARSER_H


#include <vector>
#include <map>
#include "Token.h"

enum ColumnType {
    UNDEFINED,
    STRING,
    INTEGER,
    BOOLEAN
};

struct Constriant {
    std::vector<std::string> foreignKeys;
    std::vector<std::string> localKeys;
};

struct Column {
    std::string name;
    ColumnType type;
    bool optional = false;

    explicit Column(std::string name, ColumnType type): name(name), type(type)
            {}
};

struct Table {
    std::string name;
    std::vector<Column> columns = {};
    std::vector<std::string> primaryKey = {};
    std::map<std::string, Constriant> constraints = {};

    explicit Table(std::string name): name(name)
            {}
};

struct Functions {
    std::string name;
    //name, type
    std::map<std::string, std::string> parameter = {};
    //name, value
    std::map<std::string, std::string> variables = {};

    std::string returnType;
    std::string returnValue;

    explicit Functions(std::string name): name(name)
    {}
};

struct Database {
    std::string name;
    std::vector<Table> Tables = {};
    std::vector<Functions> functions = {};

    explicit Database(std::string name): name(name)
    {}
};

struct ParsedSource {
    std::vector<Database> databases;
};



class Parser {
    std::vector<Token *> tokens;
    ParsedSource src;

    int getIndexOfDatabase(std::string db);
    int getIndexOfTable(std::string db, std::string table);
    int getIndexOfColumn(std::string db, std::string table, std::string column);

public:
    Parser(std::vector<Token *> tokens);
    ParsedSource parse();
};


#endif //NEKODBMS_PARSER_H
