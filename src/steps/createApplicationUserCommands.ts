export default function createApplicationUserCommands(db_name:string, json: any): string[] {
    const users = json.users
    //console.log(users)
    let commands: string[] = [];
    for (let user in users) {
        commands.push(`DROP USER IF EXISTS ${db_name}_${users[user].username};`)
        commands.push(`CREATE USER ${db_name}_${users[user].username} WITH PASSWORD '${users[user].password}';`)
    }
    //console.log(commands)
    return commands;

}