//
// Created by Daniel on 10/30/23.
//

#include <gtest/gtest.h>
#include "../../../src/Gateways/SourceCodeGateway.h"
#include "../../../src/Compiler/Lexer.h"
#include "../../../src/Compiler/Parser.h"
#include "../../../src/Compiler/Adapters/PostgreSQLComplier.h"


TEST(TestPostgreSQLComplier, TestFileToCompile) {
    std::string file = SourceCodeGateway::readSourceFile("../examples/example.dbms");
    Lexer lex(file);
    Parser parse(lex.lexFile());
    ParsedSource src = parse.parse();

    PostgreSQLComplier comp(src);


    SchemaInstructions commands = comp.getDBCreationCommands();

    EXPECT_EQ("CREATE DATABASE \"NekoSquare\";", commands.root.at(0));
    EXPECT_EQ("CREATE TABLE \"NekoSquare\".\"Accounts\" (\"email_address\" TEXT, \"password\" TEXT,  PRIMARY KEY (email_address));",commands.databases["NekoSquare"].tables.at(0));
    EXPECT_EQ("CREATE TABLE \"NekoSquare\".\"Tokens\" (\"email_address\" TEXT, \"token\" TEXT,  PRIMARY KEY (email_address), CONSTRAINT \"fk_accounts\"  FOREIGN KEY(email_address) REFERENCES \"Accounts\" (email_address));",commands.databases["NekoSquare"].tables.at(1));
}