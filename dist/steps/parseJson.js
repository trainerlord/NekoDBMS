"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var fs = require("fs");
function parseJson(db_name, path) {
    var jsonString = fs.readFileSync(path, "utf-8");
    var object = JSON.parse(jsonString);
    return object;
}
exports.default = parseJson;
//# sourceMappingURL=parseJson.js.map