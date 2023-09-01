export default function createStoredProcedures(
  db_name: string,
  json: any
): string[] {
  const procedures = json.procedures;
  //console.log(users)
  let commands: string[] = [];
  for (let pro in procedures) {
    let param: string = "";
    procedures[pro].parameters.forEach(element => {
        param += element + ", "
    });
    let params = param.slice(0, -2);
    //console.log(params)
    let queryies: string = "";
    procedures[pro].querys.forEach(element => {
        queryies += element
    });

    commands.push(`CREATE PROCEDURE ${procedures[pro].name}(${params})
        LANGUAGE SQL
        BEGIN ATOMIC
          ${queryies}
        END;`);
    for (let user in procedures[pro].grant) {
    commands.push(`GRANT ALL ON PROCEDURE ${procedures[pro].name} TO ${db_name}_${procedures[pro].grant[user]}`)
    }
  }
  //console.log(commands)
  return commands;
}
