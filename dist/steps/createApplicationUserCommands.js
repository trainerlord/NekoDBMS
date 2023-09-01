"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
function createApplicationUserCommands(db_name, json) {
    var users = json.users;
    //console.log(users)
    var commands = [];
    for (var user in users) {
        commands.push("DROP USER IF EXISTS ".concat(db_name, "_").concat(users[user].username, ";"));
        commands.push("CREATE USER ".concat(db_name, "_").concat(users[user].username, " WITH PASSWORD '").concat(users[user].password, "';"));
    }
    //console.log(commands)
    return commands;
}
exports.default = createApplicationUserCommands;
//# sourceMappingURL=createApplicationUserCommands.js.map