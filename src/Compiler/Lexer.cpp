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
        this->current_word = text.at(currentWord);
        if (this->text.at(currentWord).starts_with("@Schema")) {
            instructions.push_back((new  KeywordSchema())->lex(&currentWord, text));
            continue;
        }

        if (this->text.at(currentWord).starts_with("@Table")) {
            instructions.push_back((new KeywordTable())->lex(&currentWord, text));
            continue;
        }

        if (this->text.at(currentWord).starts_with("@Primary")) {
            instructions.push_back((new KeywordPrimary())->lex(&currentWord, text));
            continue;
        }

        if (this->text.at(currentWord).starts_with("@String")) {
            instructions.push_back((new KeywordString())->lex(&currentWord, text));
            continue;
        }

        if (this->text.at(currentWord).starts_with("@Integer")) {
            instructions.push_back((new KeywordInteger())->lex(&currentWord, text));
            continue;
        }

        if (this->text.at(currentWord).starts_with("@Boolean")) {
            instructions.push_back((new KeywordBoolean())->lex(&currentWord, text));
            continue;
        }

        if (this->text.at(currentWord).starts_with("@Depends")) {
            instructions.push_back((new KeywordDepends())->lex(&currentWord, text));
            continue;
        }

        if (this->text.at(currentWord).starts_with("@Null")) {
            instructions.push_back((new  KeywordDepends())->lex(&currentWord, text));
            continue;
        }

        if (this->text.at(currentWord).starts_with("}")) {
            instructions.push_back((new KeywordEnd())->lex(&currentWord, text));
            continue;
        }
    }
    return instructions;
}

/*Token Lexer::makeToken() {
    return Token(__cxx11::basic_string(), __cxx11::basic_string());
}*/
