//
// Created by Daniel on 10/26/23.
//

#include <fstream>
#include <sstream>
#include "SourceCodeGateway.h"

 std::string SourceCodeGateway::readSourceFile(std::string path) {
    std::ifstream file(path);

    if ( file )
    {
        std::stringstream buffer;

        buffer << file.rdbuf();

        file.close();

        return buffer.str();
    }
    return "";
}
