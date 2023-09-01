"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
function createStoredProcedures(db_name, json) {
    var procedures = json.procedures;
    //console.log(users)
    var commands = [];
    var _loop_1 = function (pro) {
        var param = "";
        procedures[pro].parameters.forEach(function (element) {
            param += element + ", ";
        });
        var params = param.slice(0, -2);
        //console.log(params)
        var queryies = "";
        procedures[pro].querys.forEach(function (element) {
            queryies += element;
        });
        commands.push("CREATE PROCEDURE ".concat(procedures[pro].name, "(").concat(params, ")\n        LANGUAGE SQL\n        BEGIN ATOMIC\n          ").concat(queryies, "\n        END;"));
        for (var user in procedures[pro].grant) {
            commands.push("GRANT ALL ON PROCEDURE ".concat(procedures[pro].name, " TO ").concat(db_name, "_").concat(procedures[pro].grant[user]));
        }
    };
    for (var pro in procedures) {
        _loop_1(pro);
    }
    //console.log(commands)
    return commands;
}
exports.default = createStoredProcedures;
//# sourceMappingURL=createStoredProcedures.js.map