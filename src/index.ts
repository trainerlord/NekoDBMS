#!/usr/bin/env node

const fs = require("fs");

function main() {
  console.log("Test")

  //Read JSON
  //
  const json = getJson("./src/database.json")

  const schema = json.schema;

  let tables = getJsonKeys(schema)

  console.log(tables)
  console.log(schema[0][tables[0]])
  //DROP EXISTING DB IF EXISTS

  //PARSE JSON

  //Get All the Tables From JSON
  
    //Get Column with TYPE
    
    //Get Primary Key

    //Get Contstraints

    //Build The SQL COMMNAD

}


function getJson(path: String) {
try {
  const jsonString = fs.readFileSync(path, 'utf-8');
  const object = JSON.parse(jsonString);
  return object;
  } catch (e: any) {
    console.log("Error with the Json");
    process.exit()
  }
}

function getJsonKeys(obj: any) {
  var keys = [];

  for (let i = 0; i < obj.length; i++) {
    for(var k in obj[i]) keys.push(k);
  }

  return keys;
}

main()
