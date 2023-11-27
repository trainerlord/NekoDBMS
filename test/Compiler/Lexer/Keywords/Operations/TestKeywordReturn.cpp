//
// Created by Daniel on 11/6/23.
//
#include <gtest/gtest.h>
#include "../../../../../src/Compiler/Lexer/Keywords/Operations/KeywordReturn.h"

/*
TEST(TestKeywordReturn, TestBasicReturn) {
    //@return Accounts.select(Accounts.email_address == m_email_address);

    std::vector<std::string> words = {"@return", "Accounts.select(Accounts.email_address", "==", "m_email_address);"};


    KeywordReturn key;
    int currentWord = 0;
    Token *token = key.lex(&currentWord,words);

    EXPECT_EQ(token->getValue().at(0), "Accounts.select(Accounts.email_address==m_email_address)");
    EXPECT_EQ(token->getType(), Return);
}*/