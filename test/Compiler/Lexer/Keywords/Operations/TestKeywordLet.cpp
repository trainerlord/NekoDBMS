//
// Created by Daniel on 11/6/23.
//

#include <gtest/gtest.h>
#include "../../../../../src/Compiler/Lexer/Keywords/Operations/KeywordLet.h"
/*
TEST(TestKeywordLet, TestBasicLet) {
//@let tokenAccounts;

    std::vector<std::string> words = {"@let", "testVar;"};

    KeywordLet key;
    int currentWord = 0;
    Token *token = key.lex(&currentWord, words);

    EXPECT_EQ(token->getValue().at(0), "testVar");
    EXPECT_EQ(token->getValue().at(1), "");
    EXPECT_EQ(token->getType(), Let);
}

TEST(TestKeywordLet, TestAsignmentLet) {
    //@let tokenAccounts = Accounts.join(Tokens, Tokens.email_address, Accounts.email_address);

    std::vector<std::string> words = {"@let", "testVar" , "=", "Accounts.join(Tokens,", "Tokens.email_address,", "Accounts.email_address);"};

    KeywordLet key;
    int currentWord = 0;
    Token *token = key.lex(&currentWord, words);

    EXPECT_EQ(token->getValue().at(0), "testVar");
    EXPECT_EQ(token->getValue().at(1), "Accounts.join(Tokens,Tokens.email_address,Accounts.email_address)");
    EXPECT_EQ(token->getType(), Let);
}
*/