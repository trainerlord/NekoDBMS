//
// Created by Daniel on 11/6/23.
//

#include <sstream>
#include <iostream>
#include "KeywordLet.h"

Token *KeywordLet::lex(int *currentWordIndex, std::vector<std::string> text) {
    std::stringstream line;
    *currentWordIndex -= 1;
    do {
        *currentWordIndex += 1;
        line << text.at(*currentWordIndex);
    } while (!text.at(*currentWordIndex).ends_with(';'));

    //drop return
    std::string full =  line.str().substr(line.str().find_first_of("@let")+4);
    //drop ;
    full.pop_back();

    std::cout << full.find_first_of( '=') << std::endl;
    if (full.find('=') == std::string::npos) {
        return new Token(Let, {full, ""});
    }
    std::string name = full.substr(0,full.find_first_of('='));
    std::string value = full.substr(full.find_first_of('=') + 1, full.length());

    return new Token(Let, {name, value});
}

