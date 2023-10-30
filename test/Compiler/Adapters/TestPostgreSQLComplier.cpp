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

    for (std::string command: comp.getDBCreationCommands()) {
        std::cout << command << std::endl;
    }

    EXPECT_EQ(1, 1);
}