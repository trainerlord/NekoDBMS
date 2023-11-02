//
// Created by Daniel on 10/25/23.
//

#include <format>
#include <vector>
#include <sstream>
#include <iterator>
#include "Lexer.h"
#include "Lexer/Keywords/KeywordSchema.h"
#include "Lexer/Keywords/KeywordTable.h"
#include "Lexer/Keywords/KeywordEnd.h"
#include "Lexer/Keywords/KeywordPrimary.h"
#include "Lexer/Keywords/KeywordString.h"
#include "Lexer/Keywords/KeywordInteger.h"
#include "Lexer/Keywords/KeywordBoolean.h"
#include "Lexer/Keywords/KeywordDepends.h"
#include "Lexer/KeywordFactory.h"

Lexer::Lexer(std::string text) {
    this->text = textBlobToVector(text);
    this->position = -1;
    this->current_word = "";
}




std::vector<std::string> Lexer::textBlobToVector(std::string text) {
    std::istringstream istr(text);
    std::vector<std::string> words((std::istream_iterator<std::string>(istr)),std::istream_iterator<std::string>());
    return words;
}

std::vector<Token *> Lexer::lexFile() {
    //text is the blob of stuff
    std::vector<Token *> instructions;
    for (int currentWord = 0; currentWord < this->text.size(); currentWord++) {
        //this->current_word = text.at(currentWord);
        BasicKeyword *operation = KeywordFactory::createKeyword(this->text.at(currentWord));
        instructions.push_back(operation->lex(&currentWord, text));
    }
    return instructions;
}
