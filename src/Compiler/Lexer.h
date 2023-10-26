//
// Created by Daniel on 10/25/23.
//

#ifndef NEKODBMS_LEXER_H
#define NEKODBMS_LEXER_H

#include <string>
#include "Token.h"

class Lexer {
    std::vector<std::string> text;
    int position;
    std::string current_word;

public:
    Lexer(std::string text);
    std::vector<Token> lexFile();

    static  std::vector<std::string> textBlobToVector(std::string text);
};





#endif //NEKODBMS_LEXER_H
