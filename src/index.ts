#!/usr/bin/env node

const fs = require("fs");

function main() {
  console.log("Test")

  //Read JSON
  //
  const json = getJson("./src/database.json")

  const schema = json.schema;

  let tables = getJsonKeys(schema)

  let sqlCommands: string[] = []

  //console.log(schema[0][tables[0]]['Columns'])
  //DROP EXISTING DB IF EXISTS
  sqlCommands.push("CREATE DATABASE testing;")

  for(let i = 0; i < tables.length; i++) {
    let createTable = `CREATE TABLE ${tables[i]}(`
    const cols = schema[i][tables[i]]['Columns']

    //console.log(cols)
    for(let c in cols) {
      //console.log(c)

      createTable += `${c} ${schema[i][tables[i]]['Columns'][c]},`
    }

    createTable += `PRIMARY KEY (${schema[i][tables[i]]['Primary_Key']});`
    


    sqlCommands.push(createTable)
    
    if (schema[i][tables[i]]["Constraints"] == undefined) {
      continue;
    }

    let index = 0
    for (let fk in schema[i][tables[i]]["Constraints"]) {
      const constrain = schema[i][tables[i]]["Constraints"]
        console.log(constrain[fk])

      let foreignConstrants: string = `ALTER TABLE ${tables[i]} ADD CONSTRAINT fk-${[tables[i]]}-${index} FOREIGN KEY (${constrain[fk]['Child'].split('.')[0]}) REFERENCES ${constrain[fk]['Parent'].replace('.', ' (')});`
        sqlCommands.push(foreignConstrants);

      index += 1

      
    }
    //Constraints
  }


  console.log(sqlCommands)

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
