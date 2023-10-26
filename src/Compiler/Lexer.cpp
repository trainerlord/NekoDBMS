//
// Created by Daniel on 10/25/23.
//

#include <format>
#include <vector>
#include <sstream>
#include <iterator>
#include "Lexer.h"

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

std::vector<Token> Lexer::lexFile() {
    //text is the blob of stuff
    std::vector<Token> instructions;

    for (int currentWord = 0; currentWord < this->text.size(); currentWord++) {
        this->current_word = text.at(currentWord);
        if (this->text.at(currentWord) == "@Schema") {
            if (this->text.at(currentWord + 1) == "{" && this->text.at(currentWord + 2) != "{") {
                //Source Code Format Error
                throw std::invalid_argument("Invaild Source Code");
            }
            instructions.push_back(Token(CreateDatabase,{text.at(currentWord + 1)}));
            currentWord += 2;
            continue;
        }

        if (this->text.at(currentWord) == "@Table") {
            if (this->text.at(currentWord + 1) == "{" && this->text.at(currentWord + 2) != "{") {
                //Source Code Format Error
                throw std::invalid_argument("Invaild Source Code");
            }
            instructions.push_back(Token(CreateTable,{text.at(currentWord + 1)}));
            currentWord += 2;
            continue;
        }

        if (this->text.at(currentWord) == "}") {
            instructions.push_back(Token(End,{}));
            continue;
        }

        if (this->text.at(currentWord).starts_with('@')) {
            std::vector<std::string> keywords;
            std::string attribute;

            while (text.at(currentWord).starts_with('@')) {
                if (text.at(currentWord).starts_with("@Depends")) {
                    std::stringstream dependsKeyWord;
                    currentWord--;
                    do {
                        currentWord++;
                        dependsKeyWord << text.at(currentWord);
                    } while (!text.at(currentWord).ends_with(")"));

                    keywords.push_back(dependsKeyWord.str());
                    currentWord++;
                    continue;
                }


                keywords.push_back(text.at(currentWord));
                currentWord++;
            }
            attribute = text.at(currentWord);

            if (!attribute.ends_with(';')) {
                throw std::invalid_argument("Invaild Source Code");
            }
            attribute.pop_back();

            //Handle Every Other Keywords
            for(std::string keyword : keywords) {
                if (keyword == "@Primary") {
                    instructions.push_back(Token(SetPrimaryKey, {attribute}));
                    continue;
                }
                if (keyword == "@String") {
                    instructions.push_back(Token(String, {attribute}));
                    continue;
                }
                if (keyword == "@Integer") {
                    instructions.push_back(Token(Integer, {attribute}));
                    continue;
                }
                if (keyword == "@Boolean") {
                    instructions.push_back(Token(Boolean, {attribute}));
                    continue;
                }
                if (keyword.starts_with("@Depends")) {
                    //Parse the Parameters
                    unsigned first = keyword.find('(') + 1;
                    unsigned last = keyword.find(')');
                    std::string args = keyword.substr (first,last-first);

                    std::stringstream ss( "1,1,1,1, or something else ,1,1,1,0" );
                    std::vector<std::string> result;

                    result.push_back(attribute);
                    while( ss.good() )
                    {
                        std::string substr;
                        getline( ss, substr, ',' );
                        result.push_back( substr );
                    }


                    instructions.emplace_back(SetForeignKey, result);
                    continue;
                }
                if (keyword == "@Null") {
                    instructions.push_back(Token(SetNull, {attribute}));
                    continue;
                }
                throw std::invalid_argument("Invaild Source Code");
            }
            continue;
        }
        throw std::invalid_argument("Invaild Source Code");
    }



    return instructions;
}

/*Token Lexer::makeToken() {
    return Token(__cxx11::basic_string(), __cxx11::basic_string());
}*/
