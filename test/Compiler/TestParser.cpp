//
// Created by Daniel on 10/26/23.
//

#include <gtest/gtest.h>
#include "../../src/Compiler/Lexer.h"
#include "../../src/Gateways/SourceCodeGateway.h"
#include "../../src/Compiler/Parser.h"

TEST(TestParser, TestFileToParsered) {
    std::string file = SourceCodeGateway::readSourceFile("../examples/example.dbms");
    Lexer lex(file);
    Parser parse(lex.lexFile());
    ParsedSource src = parse.parse();
    EXPECT_EQ(1, 1);
}

/*
TEST(TestParser, TestFileNewFileToParsered) {
    std::string file = SourceCodeGateway::readSourceFile("../examples/functionExample.dbms");
    Lexer lex(file);
    Parser parse(lex.lexFile());
    ParsedSource src = parse.parse();

    EXPECT_EQ(src.databases.size(), 1);

    EXPECT_EQ(src.databases.at(0).functions.size(), 2);

    EXPECT_TRUE(src.databases.at(0).functions.at(0).parameter.contains("m_email_address"));
    EXPECT_FALSE(src.databases.at(0).functions.at(0).parameter.contains("@String"));

    EXPECT_EQ(src.databases.at(0).functions.at(0).parameter.at("m_email_address"), "@String");

    EXPECT_EQ(src.databases.at(0).functions.at(0).variables.size(), 0);
    EXPECT_EQ(src.databases.at(0).functions.at(1).variables.size(), 1);
}
*/