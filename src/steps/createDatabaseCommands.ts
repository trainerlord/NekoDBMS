export default async function createDatabaseCommands(db_name:string, json: any): Promise<string[]> {
  const schema = json.schema;

  let sqlCommands: string[] = [];

  let tables = getJsonKeys(schema);

  for (let i = 0; i < tables.length; i++) {
    let createTable = `CREATE TABLE ${tables[i]}(`;
    const cols = schema[i][tables[i]]["Columns"];

    for (let c in cols) {
      createTable += `${c} ${schema[i][tables[i]]["Columns"][c]},`;
    }

    createTable += ` PRIMARY KEY (${schema[i][tables[i]]["Primary_Key"]}));`;

    sqlCommands.push(createTable);

    if (schema[i][tables[i]]["Constraints"] == undefined) {
      continue;
    }

    let index = 0;
    for (let fk in schema[i][tables[i]]["Constraints"]) {
      const constrain = schema[i][tables[i]]["Constraints"];
      //console.log(constrain[fk]);

      let foreignConstrants: string = `ALTER TABLE ${
        tables[i]
      } ADD CONSTRAINT fk_${[tables[i]]}_${index} FOREIGN KEY (${
        constrain[fk]["Child"].split(".")[1]
      }) REFERENCES ${constrain[fk]["Parent"].replace(".", " (")});`;
      sqlCommands.push(foreignConstrants);

      index += 1;
    }
  }

  return sqlCommands;
}

function getJsonKeys(obj: any) {
  var keys = [];

  for (let i = 0; i < obj.length; i++) {
    for (var k in obj[i]) keys.push(k);
  }

  return keys;
}
