//
// Created by Daniel on 10/26/23.
//

#include <gtest/gtest.h>
#include "../../src/Gateways/SourceCodeGateway.h"
#include "../../src/Compiler/Lexer.h"

TEST(TestLexer, TestFileToVector) {
    std::string file = SourceCodeGateway::readSourceFile("../example.dbms");

    std::vector<std::string> words = Lexer::textBlobToVector(file);

    EXPECT_EQ(24, words.size());
    return;
    for(std::string word : words)
    {
        std::cout << word << std::endl;
    }
}

TEST(TestLexer, TestFileToTokens) {
    std::string file = SourceCodeGateway::readSourceFile("../example.dbms");

    Lexer lex(file);

    std::vector<Token *> tokens = lex.lexFile();
    EXPECT_EQ(13, tokens.size());

    EXPECT_EQ(tokens.at(8)->toString(), "3:email_address,Accounts.email_address,\"fk_accounts\"");

    for(Token *token : tokens)
    {
        std::cout << token->toString() << std::endl;
    }

    //EXPECT_EQ(1, 1);
}