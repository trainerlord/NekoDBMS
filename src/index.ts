#!/usr/bin/env node

import parseJson from './steps/parseJson';

import createDatabaseCommands from './steps/createDatabaseCommands';
import executeCommands from './steps/executeCommands';
import createApplicationUserCommands from './steps/createApplicationUserCommands';
import createStoredProcedures from './steps/createStoredProcedures';

const DATABASE_NAME = "testing"

async function main() {
  //console.log("Test");

  var args = process.argv.slice(2);

  //console.log(args)
  let json: any
  try {
  json = parseJson(args[0], args[1]);
  } catch {
    console.log("Usage: database-builder <Database Name> <Database Schema Json>")
    process.exit(0)
  }

  let sql:string[] = await createDatabaseCommands(args[0],json);

  sql = sql.concat(createApplicationUserCommands(args[0],json))

  sql = sql.concat(createStoredProcedures(args[0], json))
  //console.log(sql)
  await executeCommands(args[0], sql);
}

main();
