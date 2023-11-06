//
// Created by Daniel on 11/6/23.
//

#include <sstream>
#include <iostream>
#include "KeywordFunction.h"

Token *KeywordFunction::lex(int *currentWordIndex, std::vector <std::string> text) {
    std::stringstream line;
    *currentWordIndex -= 1;
    do {
        *currentWordIndex += 1;
        line << text.at(*currentWordIndex);
    } while (!text.at(*currentWordIndex).starts_with('{'));

    if (text.at(*currentWordIndex).ends_with("{}")) {
        *currentWordIndex -= 1;
    }
    //@FunctiongetAllTokensAndAccount():Accounts&Tokens {
    //drop @Function
    std::string full =  line.str().substr(line.str().find_first_of("@Function")+9);
    //drop ;
    full.pop_back();

    if (full.find(':') == std::string::npos) {
        std::cout << "No Return Definition for function"<< std::endl;
        exit(0);
    }
    std::string name = full.substr(0,full.find_first_of('('));
    std::string parameters = full.substr(full.find_first_of('(') + 1,full.find_first_of(')') - full.find_first_of('(') - 1 );
    std::string value = full.substr(full.find_first_of(':') + 1, full.find_first_of('{') - full.find_first_of(':') - 1);

    return new Token(CreateFunction, {name, parameters, value});
}
