#!/usr/bin/env node
"use strict";
var __awaiter = (this && this.__awaiter) || function (thisArg, _arguments, P, generator) {
    function adopt(value) { return value instanceof P ? value : new P(function (resolve) { resolve(value); }); }
    return new (P || (P = Promise))(function (resolve, reject) {
        function fulfilled(value) { try { step(generator.next(value)); } catch (e) { reject(e); } }
        function rejected(value) { try { step(generator["throw"](value)); } catch (e) { reject(e); } }
        function step(result) { result.done ? resolve(result.value) : adopt(result.value).then(fulfilled, rejected); }
        step((generator = generator.apply(thisArg, _arguments || [])).next());
    });
};
var __generator = (this && this.__generator) || function (thisArg, body) {
    var _ = { label: 0, sent: function() { if (t[0] & 1) throw t[1]; return t[1]; }, trys: [], ops: [] }, f, y, t, g;
    return g = { next: verb(0), "throw": verb(1), "return": verb(2) }, typeof Symbol === "function" && (g[Symbol.iterator] = function() { return this; }), g;
    function verb(n) { return function (v) { return step([n, v]); }; }
    function step(op) {
        if (f) throw new TypeError("Generator is already executing.");
        while (g && (g = 0, op[0] && (_ = 0)), _) try {
            if (f = 1, y && (t = op[0] & 2 ? y["return"] : op[0] ? y["throw"] || ((t = y["return"]) && t.call(y), 0) : y.next) && !(t = t.call(y, op[1])).done) return t;
            if (y = 0, t) op = [op[0] & 2, t.value];
            switch (op[0]) {
                case 0: case 1: t = op; break;
                case 4: _.label++; return { value: op[1], done: false };
                case 5: _.label++; y = op[1]; op = [0]; continue;
                case 7: op = _.ops.pop(); _.trys.pop(); continue;
                default:
                    if (!(t = _.trys, t = t.length > 0 && t[t.length - 1]) && (op[0] === 6 || op[0] === 2)) { _ = 0; continue; }
                    if (op[0] === 3 && (!t || (op[1] > t[0] && op[1] < t[3]))) { _.label = op[1]; break; }
                    if (op[0] === 6 && _.label < t[1]) { _.label = t[1]; t = op; break; }
                    if (t && _.label < t[2]) { _.label = t[2]; _.ops.push(op); break; }
                    if (t[2]) _.ops.pop();
                    _.trys.pop(); continue;
            }
            op = body.call(thisArg, _);
        } catch (e) { op = [6, e]; y = 0; } finally { f = t = 0; }
        if (op[0] & 5) throw op[1]; return { value: op[0] ? op[1] : void 0, done: true };
    }
};
Object.defineProperty(exports, "__esModule", { value: true });
var pg_1 = require("pg");
var fs = require("fs");
function main() {
    return __awaiter(this, void 0, void 0, function () {
        var json, schema, tables, sqlCommands, i, createTable, cols, c, index, fk, constrain, foreignConstrants, client, sql, com, e_1;
        return __generator(this, function (_a) {
            switch (_a.label) {
                case 0:
                    console.log("Test");
                    json = getJson("./src/database.json");
                    schema = json.schema;
                    tables = getJsonKeys(schema);
                    sqlCommands = [];
                    //console.log(schema[0][tables[0]]['Columns'])
                    //DROP EXISTING DB IF EXISTS
                    //sqlCommands.push("CREATE DATABASE Development;");
                    for (i = 0; i < tables.length; i++) {
                        createTable = "CREATE TABLE ".concat(tables[i], "(");
                        cols = schema[i][tables[i]]["Columns"];
                        //console.log(cols)
                        for (c in cols) {
                            //console.log(c)
                            createTable += "".concat(c, " ").concat(schema[i][tables[i]]["Columns"][c], ",");
                        }
                        createTable += " PRIMARY KEY (".concat(schema[i][tables[i]]["Primary_Key"], "));");
                        sqlCommands.push(createTable);
                        if (schema[i][tables[i]]["Constraints"] == undefined) {
                            continue;
                        }
                        index = 0;
                        for (fk in schema[i][tables[i]]["Constraints"]) {
                            constrain = schema[i][tables[i]]["Constraints"];
                            console.log(constrain[fk]);
                            foreignConstrants = "ALTER TABLE ".concat(tables[i], " ADD CONSTRAINT fk_").concat([tables[i]], "_").concat(index, " FOREIGN KEY (").concat(constrain[fk]["Child"].split(".")[1], ") REFERENCES ").concat(constrain[fk]["Parent"].replace(".", " ("), ");");
                            sqlCommands.push(foreignConstrants);
                            index += 1;
                        }
                        //Constraints
                    }
                    console.log(sqlCommands);
                    client = new pg_1.Client({
                        //host: 'localhost',
                        //port: 5334,
                        //database:"Testing",
                        user: 'postgres',
                        password: 'Dan1iel2',
                    });
                    return [4 /*yield*/, client.connect()];
                case 1:
                    _a.sent();
                    return [4 /*yield*/, client.query("DROP DATABASE IF EXISTS development;")];
                case 2:
                    _a.sent();
                    return [4 /*yield*/, client.query("CREATE DATABASE development;")];
                case 3:
                    _a.sent();
                    return [4 /*yield*/, client.end()];
                case 4:
                    _a.sent();
                    sql = new pg_1.Client({
                        //host: 'localhost',
                        //port: 5334,
                        database: "development",
                        user: 'postgres',
                        password: 'Dan1iel2',
                    });
                    _a.label = 5;
                case 5:
                    _a.trys.push([5, 11, , 12]);
                    return [4 /*yield*/, sql.connect()];
                case 6:
                    _a.sent();
                    com = 0;
                    _a.label = 7;
                case 7:
                    if (!(com < sqlCommands.length)) return [3 /*break*/, 10];
                    console.log(sqlCommands[com]);
                    return [4 /*yield*/, sql.query(sqlCommands[com])];
                case 8:
                    _a.sent();
                    _a.label = 9;
                case 9:
                    com++;
                    return [3 /*break*/, 7];
                case 10: return [3 /*break*/, 12];
                case 11:
                    e_1 = _a.sent();
                    console.log(e_1);
                    return [3 /*break*/, 12];
                case 12: return [4 /*yield*/, sql.end()
                    //PARSE JSON
                    //Get All the Tables From JSON
                    //Get Column with TYPE
                    //Get Primary Key
                    //Get Contstraints
                    //Build The SQL COMMNAD
                ];
                case 13:
                    _a.sent();
                    return [2 /*return*/];
            }
        });
    });
}
function getJson(path) {
    try {
        var jsonString = fs.readFileSync(path, "utf-8");
        var object = JSON.parse(jsonString);
        return object;
    }
    catch (e) {
        console.log("Error with the Json");
        process.exit();
    }
}
function getJsonKeys(obj) {
    var keys = [];
    for (var i = 0; i < obj.length; i++) {
        for (var k in obj[i])
            keys.push(k);
    }
    return keys;
}
main();
