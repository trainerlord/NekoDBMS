//
// Created by Daniel on 10/26/23.
//

#ifndef NEKODBMS_SOURCECODEGATEWAY_H
#define NEKODBMS_SOURCECODEGATEWAY_H


#include <string>

class SourceCodeGateway {
public:
    static std::string readSourceFile(std::string path);
};


#endif //NEKODBMS_SOURCECODEGATEWAY_H
