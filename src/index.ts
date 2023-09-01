#!/usr/bin/env node

import parseJson from './steps/parseJson';

import createDatabaseCommands from './steps/createDatabaseCommands';
import executeCommands from './steps/executeCommands';
import createApplicationUserCommands from './steps/createApplicationUserCommands';
import createStoredProcedures from './steps/createStoredProcedures';

const DATABASE_NAME = "testing"

async function main() {
  //console.log("Test");

  //Read JSON
  //
  const json = parseJson(DATABASE_NAME, "./src/database.json");

  let sql:string[] = await createDatabaseCommands(DATABASE_NAME,json);

  sql = sql.concat(createApplicationUserCommands(DATABASE_NAME,json))

  sql = sql.concat(createStoredProcedures(DATABASE_NAME, json))
  //console.log(sql)
  await executeCommands(DATABASE_NAME, sql);
}

main();
