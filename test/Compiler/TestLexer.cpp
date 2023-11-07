//
// Created by Daniel on 10/26/23.
//

#include <gtest/gtest.h>
#include "../../src/Gateways/SourceCodeGateway.h"
#include "../../src/Compiler/Lexer.h"

TEST(TestLexer, TestFileToVector) {
    std::string file = SourceCodeGateway::readSourceFile("../examples/example.dbms");

    std::vector<std::string> words = Lexer::textBlobToVector(file);

    EXPECT_EQ(35, words.size());

    for(std::string word : words)
    {
        std::cout << word << std::endl;
    }
}

TEST(TestLexer, TestFileToTokens) {
    std::string file = SourceCodeGateway::readSourceFile("../examples/example.dbms");

    Lexer lex(file);

    std::vector<Token *> tokens = lex.lexFile();
    EXPECT_EQ(13, tokens.size());

    EXPECT_EQ(tokens.at(8)->toString(), "4:email_address,Accounts.email_address,\"fk_accounts\"");

    for(Token *token : tokens)
    {
        std::cout << token->toString() << std::endl;
    }

    //EXPECT_EQ(1, 1);
}

TEST(TestLexer, TestEmptySchemaToTokens) {
    std::string file = "@Schema emptySchema {}";

    Lexer lex(file);

    std::vector<std::string> words = Lexer::textBlobToVector(file);
    for(std::string word : words)
    {
        std::cout << word << std::endl;
    }

    std::vector<Token *> tokens = lex.lexFile();
    EXPECT_EQ(2, tokens.size());

    EXPECT_EQ(tokens.at(0)->getType(), CreateDatabase);
    EXPECT_EQ(tokens.at(0)->getValue().at(0), "emptySchema");

    EXPECT_EQ(tokens.at(1)->getType(), End);
    //EXPECT_EQ(1, 1);
}

TEST(TestLexer, TestEmptySchemaWSplitToTokens) {
    std::string file = "@Schema emptySchema { }";

    Lexer lex(file);

    std::vector<Token *> tokens = lex.lexFile();
    EXPECT_EQ(2, tokens.size());

    EXPECT_EQ(tokens.at(0)->getType(), CreateDatabase);
    EXPECT_EQ(tokens.at(0)->getValue().at(0), "emptySchema");

    EXPECT_EQ(tokens.at(1)->getType(), End);
    //EXPECT_EQ(1, 1);
}

TEST(TestLexer, TestFuncFileToTokens) {
    std::string file = SourceCodeGateway::readSourceFile("../examples/functionExample.dbms");

    Lexer lex(file);

    std::vector<Token *> tokens = lex.lexFile();
    EXPECT_EQ(20, tokens.size());


    for(Token *token : tokens)
    {
        std::cout << token->toString() << std::endl;
    }

    //EXPECT_EQ(1, 1);
}

TEST(TestLexer, TestFuncFileToWithCommentsTokens) {
    std::string file = SourceCodeGateway::readSourceFile("../examples/functionExampleComments.dbms");

    Lexer lex(file);

    std::vector<Token *> tokens = lex.lexFile();
    EXPECT_EQ(20, tokens.size());


    for(Token *token : tokens)
    {
        std::cout << token->toString() << std::endl;
    }

    //EXPECT_EQ(1, 1);
}