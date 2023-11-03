//
// Created by Daniel on 10/31/23.
//

#include <sstream>
#include "KeywordDepends.h"
#include "../Abstract/Observer.h"

Token *KeywordDepends::lex(int *currentWordIndex, std::vector<std::string> text) {
    std::vector<std::string> keywords;

    //Get Arg String
    std::stringstream dependsKeyWord;
    *currentWordIndex -= 1;
    do {
        *currentWordIndex += 1;
        dependsKeyWord << text.at(*currentWordIndex);
    } while (!text.at(*currentWordIndex).ends_with(')'));
    std::string parameters = dependsKeyWord.str();

    //Create Arg Vector
    unsigned first = parameters.find('(') + 1;
    unsigned last = parameters.find(')');
    std::string args = parameters.substr (first,last-first);

    std::stringstream ss(args);
    std::string temporayRefrence;
    std::vector<std::string> result;


    std::string debug = ss.str();
    //blank col name
    result.push_back("");
    while (std::getline(ss, temporayRefrence, ',')) {
        result.push_back(temporayRefrence);
    }

    Token *temp = new Token(SetForeignKey, result);
    this->token = temp;
    Observer::getInst()->awaitAttribute(this);
    checkAttribute(currentWordIndex, text);
    return this->token;
}

void KeywordDepends::updateAttribute(std::vector<std::string> att)  {
    std::vector<std::string> args = this->token->getValue();
    args[0] = att.at(0);
    for (std::string arg : args ) {

    }
    this->token->setValue(args);
}
