
import { Client } from 'pg'

export default async function executeCommands(db_name:string, sqlCommands: string[]): Promise<void> {
    const client = new Client({
        user: 'postgres',
        password: 'Dan1iel2',
      });
      await client.connect();
      await client.query(`DROP DATABASE IF EXISTS ${db_name};`)
      await client.query(`CREATE DATABASE ${db_name};`)
    
      await client.end()
    
    
      const sql = new Client({
        //host: 'localhost',
        //port: 5334,
        database: db_name,
        user: 'postgres',
        password: 'Dan1iel2',
      });
    
      try {
      await sql.connect();
      for (let com = 0; com < sqlCommands.length; com++) {
        //console.log(sqlCommands[com])
        await sql.query(sqlCommands[com]);
      }
      } catch(e: any) {
        console.log(e)
      }
    
      await sql.end()
}