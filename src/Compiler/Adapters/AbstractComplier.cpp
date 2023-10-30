//
// Created by Daniel Byomujuni on 10/27/23.
//

#include "AbstractComplier.h"

std::vector<std::string> AbstractComplier::getDBCreationCommands() {
    std::vector<std::string> cmds;

    for(const Database& db : this->src.databases) {
        cmds.push_back(this->createDBCommand(db));

        for (const Table& table : db.Tables) {
            cmds.push_back(this->createTableCommand(db.name, table));
        }

    }

    return cmds;
}
