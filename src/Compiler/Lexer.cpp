//
// Created by Daniel on 10/25/23.
//

#include <format>
#include <vector>
#include <sstream>
#include <iterator>
#include <iostream>
#include "Lexer.h"
#include "Lexer/Keywords/Constructors/KeywordSchema.h"
#include "Lexer/Keywords/Constructors/KeywordTable.h"
#include "Lexer/Keywords/Operations/KeywordEnd.h"
#include "Lexer/Keywords/Types/KeywordPrimary.h"
#include "Lexer/Keywords/Types/KeywordString.h"
#include "Lexer/Keywords/Types/KeywordInteger.h"
#include "Lexer/Keywords/Types/KeywordBoolean.h"
#include "Lexer/Keywords/Operations/KeywordDepends.h"
#include "Lexer/KeywordFactory.h"

Lexer::Lexer(std::string text) {
    this->text = textBlobToVector(text);
    this->position = -1;
    this->current_word = "";
}




std::vector<std::string> Lexer::textBlobToVector(std::string text) {
    std::vector<std::string> words = {};

    std::stringstream word;
    for (int i = 0; i < text.length(); i++) {
        if (text.at(i) == ' ' || text.at(i) == '\t') {
            if (!word.str().empty()) {
                //std::cout << word.str() << std::endl;
                words.push_back(word.str());
                word.str("");
            }
            continue;
        }
        if (text.at(i) == '\n') {
            if (!word.str().empty()) {
                //std::cout << word.str() << std::endl;
                words.push_back(word.str());
                word.str("");
            }
            words.push_back("\n");
            continue;
        }
        word << text.at(i);

        if (i == text.size()-1) {
            words.push_back(word.str());
        }
    }

    return words;

}

std::vector<Token *> Lexer::lexFile() {
    //text is the blob of stuff
    std::vector<Token *> instructions;
    for (int currentWord = 0; currentWord < this->text.size(); currentWord++) {
        //this->current_word = text.at(currentWord);
        if (this->text.at(currentWord) == "\n") {
            continue;
        }

        if (this->text.at(currentWord).starts_with("//")) {
            while (this->text.at(currentWord) != "\n") {
                //std::cout << this->text.at(currentWord);
                currentWord++;
            }
            continue;
        }

        if (this->text.at(currentWord).starts_with("/*")) {
            while (!this->text.at(currentWord).ends_with("*/")) {
                //std::cout << this->text.at(currentWord);
                currentWord++;
            }
            continue;
        }

        BasicKeyword *operation = KeywordFactory::createKeyword(this->text.at(currentWord));
        instructions.push_back(operation->lex(&currentWord, text));
    }
    return instructions;
}
