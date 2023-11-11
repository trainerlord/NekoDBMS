//
// Created by Daniel Byomujuni on 10/27/23.
//

#include "AbstractComplier.h"
#include "SchemaInstructions.h"

SchemaInstructions AbstractComplier::getDBCreationCommands() {
    SchemaInstructions cmds;

    for(const Database& db : this->src.databases) {
        cmds.root.push_back(this->createDBCommand(db));
        cmds.databases[db.name] = DatabaseInstructions {db.name};

        for (const Table& table : db.Tables) {
            cmds.databases.at(db.name).tables.push_back(this->createTableCommand(db.name, table));
        }

        for (const Functions& func : db.functions) {
            cmds.databases.at(db.name).functions.push_back(this->createFunctionCommand(db.name, func));
        }

    }

    return cmds;
}
