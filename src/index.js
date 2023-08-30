#!/usr/bin/env node
var fs = require("fs");
function main() {
    console.log("Test");
    //Read JSON
    //
    var json = getJson("./src/database.json");
    var schema = json.schema;
    var tables = getJsonKeys(schema);
    var sqlCommands = [];
    //console.log(schema[0][tables[0]]['Columns'])
    //DROP EXISTING DB IF EXISTS
    sqlCommands.push("CREATE DATABASE testing;");
    for (var i = 0; i < tables.length; i++) {
        var createTable = "CREATE TABLE ".concat(tables[i], "(");
        var cols = schema[i][tables[i]]['Columns'];
        //console.log(cols)
        for (var c in cols) {
            //console.log(c)
            createTable += "".concat(c, " ").concat(schema[i][tables[i]]['Columns'][c], ",");
        }
        createTable += "PRIMARY KEY (".concat(schema[i][tables[i]]['Primary_Key'], ");");
        sqlCommands.push(createTable);
        if (schema[i][tables[i]]["Constraints"] == undefined) {
            continue;
        }
        var index = 0;
        for (var fk in schema[i][tables[i]]["Constraints"]) {
            var constrain = schema[i][tables[i]]["Constraints"];
            console.log(constrain[fk]);
            var foreignConstrants = "ALTER TABLE ".concat(tables[i], " ADD CONSTRAINT fk-").concat([tables[i]], "-").concat(index, " FOREIGN KEY (").concat(constrain[fk]['Child'].split('.')[0], ") REFERENCES ").concat(constrain[fk]['Parent'].replace('.', ' ('), ");");
            sqlCommands.push(foreignConstrants);
            index += 1;
        }
        //Constraints
    }
    console.log(sqlCommands);
    //PARSE JSON
    //Get All the Tables From JSON
    //Get Column with TYPE
    //Get Primary Key
    //Get Contstraints
    //Build The SQL COMMNAD
}
function getJson(path) {
    try {
        var jsonString = fs.readFileSync(path, 'utf-8');
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
