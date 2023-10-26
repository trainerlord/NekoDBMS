cmake_minimum_required(VERSION 3.24)
project(NekoDBMS)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)


add_executable(NekoDBMS src/main.cpp
        src/Compiler/Lexer.h
        src/Compiler/Lexer.cpp
        src/Compiler/Token.cpp
        src/Gateways/SourceCodeGateway.h
        src/Gateways/SourceCodeGateway.cpp
        src/Compiler/Paser.cpp
        src/Compiler/Paser.h)

enable_testing()

add_executable(
        NekoDBMSTest
        src/Compiler/Lexer.h
        src/Compiler/Lexer.cpp
        src/Compiler/Token.cpp
        src/Gateways/SourceCodeGateway.h
        src/Gateways/SourceCodeGateway.cpp
        test/Gateways/TestSourceCodeGateway.cpp
        test/Compiler/TestLexer.cpp
        src/Compiler/Paser.cpp
        src/Compiler/Paser.h
        test/Compiler/TestParser.cpp)
target_link_libraries(
        NekoDBMSTest
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(NekoDBMSTest)

