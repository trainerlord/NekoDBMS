//
// Created by Daniel on 10/26/23.
//

#include "Paser.h"

Paser::Paser(std::vector<Token *> tokens) {
    this->tokens = tokens;
}

ParsedSource Paser::parse() {
    std::string currentDatabase;
    std::string currentTable;
    int columnIndex = -1;

    for (Token *token : this->tokens) {

        switch (token->getType()) {
            case CreateDatabase:
                this->src.databases.emplace_back(token->getValue().at(0));
                currentDatabase = token->getValue().at(0);
                break;
            case CreateTable:
                this->src.databases.at(this->getIndexOfDatabase(currentDatabase)).Tables
                .emplace_back(token->getValue().at(0));
                currentTable = token->getValue().at(0);
                break;
            case SetPrimaryKey:
                this->src.databases.at(this->getIndexOfDatabase(currentDatabase)).Tables.at(this->getIndexOfTable(currentDatabase, currentTable))
                .primaryKey.emplace_back(token->getValue().at(0));
                break;
            case SetForeignKey:
                this->src.databases.at(this->getIndexOfDatabase(currentDatabase)).Tables.at(this->getIndexOfTable(currentDatabase, currentTable))
                .constraints[token->getValue().at(2)].foreignKeys.push_back(token->getValue().at(1));

                this->src.databases.at(this->getIndexOfDatabase(currentDatabase)).Tables.at(this->getIndexOfTable(currentDatabase, currentTable))
                        .constraints[token->getValue().at(2)].localKeys.push_back(token->getValue().at(0));

                break;
            case SetNull:
                columnIndex = this->getIndexOfColumn(currentDatabase, currentTable, token->getValue().at(0));
                if (columnIndex == -1) {
                    this->src.databases.at(this->getIndexOfDatabase(currentDatabase)).Tables.at(this->getIndexOfTable(currentDatabase, currentTable))
                    .columns.push_back(Column(token->getValue().at(0), UNDEFINED));
                }

                this->src.databases.at(this->getIndexOfDatabase(currentDatabase)).Tables.at(this->getIndexOfTable(currentDatabase, currentTable))
                .columns.at(this->getIndexOfColumn(currentDatabase, currentTable, token->getValue().at(0)))
                .optional = true;
                break;
            case String:
                columnIndex = this->getIndexOfColumn(currentDatabase, currentTable, token->getValue().at(0));
                if (columnIndex == -1) {
                    this->src.databases.at(this->getIndexOfDatabase(currentDatabase)).Tables.at(this->getIndexOfTable(currentDatabase, currentTable))
                            .columns.emplace_back(token->getValue().at(0), STRING);
                    break;
                }

                this->src.databases.at(this->getIndexOfDatabase(currentDatabase)).Tables.at(this->getIndexOfTable(currentDatabase, currentTable))
                .columns.at(this->getIndexOfColumn(currentDatabase, currentTable, token->getValue().at(0)))
                .type = STRING;
                break;
            case Integer:
                columnIndex = this->getIndexOfColumn(currentDatabase, currentTable, token->getValue().at(0));
                if (columnIndex == -1) {
                    this->src.databases.at(this->getIndexOfDatabase(currentDatabase)).Tables.at(this->getIndexOfTable(currentDatabase, currentTable))
                            .columns.emplace_back(token->getValue().at(0), INTEGER);
                    break;
                }

                this->src.databases.at(this->getIndexOfDatabase(currentDatabase)).Tables.at(this->getIndexOfTable(currentDatabase, currentTable))
                        .columns.at(this->getIndexOfColumn(currentDatabase, currentTable, token->getValue().at(0)))
                        .type = INTEGER;
                break;
            case Boolean:
                columnIndex = this->getIndexOfColumn(currentDatabase, currentTable, token->getValue().at(0));
                if (columnIndex == -1) {
                    this->src.databases.at(this->getIndexOfDatabase(currentDatabase)).Tables.at(this->getIndexOfTable(currentDatabase, currentTable))
                            .columns.emplace_back(token->getValue().at(0), BOOLEAN);
                    break;
                }

                this->src.databases.at(this->getIndexOfDatabase(currentDatabase)).Tables.at(this->getIndexOfTable(currentDatabase, currentTable))
                        .columns.at(this->getIndexOfColumn(currentDatabase, currentTable, token->getValue().at(0)))
                        .type = BOOLEAN;
                break;
            case End:
                if (!currentTable.empty()) {
                    currentTable = "";
                    break;
                }

                if (!currentDatabase.empty()) {
                    currentDatabase = "";
                }
                break;
        }
    }
    return src;
}

int Paser::getIndexOfDatabase(std::string db) {
    for (int index = 0; index < this->src.databases.size(); index++) {
        if (db == this->src.databases.at(index).name) {
            return index;
        }
    }

    return -1;
}

int Paser::getIndexOfTable(std::string db, std::string table) {
    int dbIndex = this->getIndexOfDatabase(db);

    for (int index = 0; index < this->src.databases.at(dbIndex).Tables.size(); index++) {
        if (table == this->src.databases.at(dbIndex).Tables.at(index).name) {
            return index;
        }
    }
    return -1;
}

int Paser::getIndexOfColumn(std::string db, std::string table, std::string column) {
    int dbIndex = this->getIndexOfDatabase(db);
    int tableIndex = this->getIndexOfTable(db, table);

    for (int index = 0; index < this->src.databases.at(dbIndex).Tables.at(tableIndex).columns.size(); index++) {
        if (table == this->src.databases.at(dbIndex).Tables.at(tableIndex).columns.at(index).name) {
            return index;
        }
    }
    return -1;
}

