//
// Created by Daniel on 10/26/23.
//

#include <gtest/gtest.h>
#include "../../src/Compiler/Lexer.h"
#include "../../src/Gateways/SourceCodeGateway.h"
#include "../../src/Compiler/Paser.h"

TEST(TestParser, TestFileToParsered) {
    std::string file = SourceCodeGateway::readSourceFile("../example.dbms");

    Lexer lex(file);
    Paser parse(lex.lexFile());

    ParsedSource src = parse.parse();

    EXPECT_EQ(1, 1);

}