//
// Created by Daniel on 10/30/23.
//

#include <gtest/gtest.h>
#include "../../../src/Gateways/SourceCodeGateway.h"
#include "../../../src/Compiler/Lexer.h"
#include "../../../src/Compiler/Paser.h"
#include "../../../src/Compiler/Adapters/PostgreSQLComplier.h"


TEST(TestPostgreSQLComplier, TestFileToCompile) {
    std::string file = SourceCodeGateway::readSourceFile("../example.dbms");
    Lexer lex(file);
    Paser parse(lex.lexFile());
    ParsedSource src = parse.parse();

    PostgreSQLComplier comp(src);


    std::vector<std::string> commands = comp.getDBCreationCommands();

    EXPECT_EQ("CREATE DATABASE \"NekoSquare\";", commands.at(0));
    EXPECT_EQ("CREATE TABLE \"NekoSquare\".\"Accounts\" (\"email_address\" TEXT, \"password\" TEXT,  PRIMARY KEY (email_address));", commands.at(1));
    EXPECT_EQ("CREATE TABLE \"NekoSquare\".\"Tokens\" (\"email_address\" TEXT, \"token\" TEXT,  PRIMARY KEY (email_address), CONSTRAINT \"fk_accounts\"  FOREIGN KEY(email_address) REFERENCES \"Accounts\" (email_address));", commands.at(2));

}