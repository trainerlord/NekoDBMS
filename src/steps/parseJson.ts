const fs = require("fs");

export default function parseJson(db_name:string, path: String): any {
    const jsonString = fs.readFileSync(path, "utf-8");
    const object = JSON.parse(jsonString);
    return object;
}
