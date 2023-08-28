#!/usr/bin/env node
var fs = require("fs");
function main() {
    console.log("Test");
    //Read JSON
    //
    var json = getJson("./src/database.json");
    var schema = json.schema;
    var tables = getJsonKeys(schema);
    console.log(tables);
    console.log(schema[0][tables[0]]);
    //DROP EXISTING DB IF EXISTS
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
