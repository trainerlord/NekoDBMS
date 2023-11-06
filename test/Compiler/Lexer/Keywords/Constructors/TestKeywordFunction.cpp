//
// Created by Daniel on 11/6/23.
//

#include <gtest/gtest.h>
#include "../../../../../src/Compiler/Lexer/Keywords/Constructors/KeywordFunction.h"

TEST(TestKeywordFunction, TestBasicFunction) {
//    @Function getAllTokensAndAccount(): Accounts & Tokens {}
    std::vector<std::string> words = {"@Function", "getAllTokensAndAccount():", "Accounts", "&", "Tokens", "{}"};

    KeywordFunction key;
    int currentWord = 0;
    Token *token = key.lex(&currentWord, words);

    EXPECT_EQ(token->getValue().at(0), "getAllTokensAndAccount");
    EXPECT_EQ(token->getValue().at(1), "");
    EXPECT_EQ(token->getValue().at(2), "Accounts&Tokens");
    EXPECT_EQ(token->getType(), CreateFunction);
}