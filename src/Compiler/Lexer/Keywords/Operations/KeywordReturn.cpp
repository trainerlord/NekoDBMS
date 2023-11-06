//
// Created by Daniel on 11/6/23.
//

#include <sstream>
#include "KeywordReturn.h"

Token *KeywordReturn::lex(int *currentWordIndex, std::vector<std::string> text) {
    std::stringstream line;
    *currentWordIndex -= 1;
    do {
        *currentWordIndex += 1;
        line << text.at(*currentWordIndex);
    } while (!text.at(*currentWordIndex).ends_with(';'));

    //drop return
    std::string value =  line.str().substr(line.str().find_first_of("@return")+7);
    //drop ;
    value.pop_back();
    return new Token(Return, {value});
}
