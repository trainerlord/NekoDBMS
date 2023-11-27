//
// Created by Daniel on 11/27/23.
//

#include <sstream>
#include "OperationSelect.h"

Token *OperationSelect::lex(int *currentWordIndex, std::vector<std::string> text) {
    std::vector<std::string> result;
    //Get Arg String
    std::stringstream selectwords;
    *currentWordIndex -= 1;

    result.push_back(text.at(*currentWordIndex - 1));
    do {
        *currentWordIndex += 1;
        selectwords << text.at(*currentWordIndex);
    } while (!text.at(*currentWordIndex).ends_with(');'));
    std::string parameters = selectwords.str();

    //Create Arg Vector
    unsigned first = parameters.find('(') + 1;
    unsigned last = parameters.find(')');
    std::string args = parameters.substr (first,last-first);

    std::stringstream ss(args);
    std::string temporayRefrence;



    std::string debug = ss.str();
    //blank col name
    while (std::getline(ss, temporayRefrence, ',')) {
        result.push_back(temporayRefrence);
    }

    Token *temp = new Token(Select, result);
    return temp;

}
