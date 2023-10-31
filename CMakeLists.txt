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
        src/Compiler/Paser.h src/Compiler/Adapters/AbstractComplier.cpp src/Compiler/Adapters/AbstractComplier.h src/Compiler/Adapters/PostgreSQLComplier.cpp src/Compiler/Adapters/PostgreSQLComplier.h
        src/Compiler/Lexer/Keywords/Abstract/BasicKeyword.h
        src/Compiler/Lexer/Keywords/Abstract/ObserverKeyword.cpp
        src/Compiler/Lexer/Keywords/Abstract/ObserverKeyword.h
        src/Compiler/Lexer/Keywords/KeywordSchema.cpp
        src/Compiler/Lexer/Keywords/KeywordSchema.h
        src/Compiler/Lexer/Keywords/Abstract/ObserverKeyword.cpp
        src/Compiler/Lexer/Keywords/KeywordTable.cpp
        src/Compiler/Lexer/Keywords/KeywordTable.h
        src/Compiler/Lexer/Keywords/KeywordEnd.cpp
        src/Compiler/Lexer/Keywords/KeywordEnd.h
        src/Compiler/Lexer/Keywords/KeywordPrimary.cpp
        src/Compiler/Lexer/Keywords/KeywordPrimary.h
        src/Compiler/Lexer/Keywords/KeywordString.cpp
        src/Compiler/Lexer/Keywords/KeywordString.h
        src/Compiler/Lexer/Keywords/KeywordInteger.cpp
        src/Compiler/Lexer/Keywords/KeywordInteger.h
        src/Compiler/Lexer/Keywords/KeywordBoolean.cpp
        src/Compiler/Lexer/Keywords/KeywordBoolean.h
        src/Compiler/Lexer/Keywords/KeywordDepends.cpp
        src/Compiler/Lexer/Keywords/KeywordDepends.h
        src/Compiler/Lexer/Keywords/KeywordNull.cpp
        src/Compiler/Lexer/Keywords/KeywordNull.h
        src/Compiler/Lexer/Keywords/Abstract/Observer.cpp
        src/Compiler/Lexer/Keywords/Abstract/Observer.h
)

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
        src/Compiler/Adapters/PostgreSQLComplier.cpp
        src/Compiler/Adapters/PostgreSQLComplier.h
        src/Compiler/Adapters/AbstractComplier.cpp
        src/Compiler/Adapters/AbstractComplier.h
        test/Compiler/TestParser.cpp
        test/Compiler/Adapters/TestPostgreSQLComplier.cpp
        src/Compiler/Lexer/Keywords/Abstract/BasicKeyword.h
        src/Compiler/Lexer/Keywords/Abstract/ObserverKeyword.cpp
        src/Compiler/Lexer/Keywords/Abstract/ObserverKeyword.h
        src/Compiler/Lexer/Keywords/KeywordSchema.cpp
        src/Compiler/Lexer/Keywords/KeywordSchema.h
        src/Compiler/Lexer/Keywords/Abstract/ObserverKeyword.cpp
        src/Compiler/Lexer/Keywords/KeywordTable.cpp
        src/Compiler/Lexer/Keywords/KeywordTable.h
        src/Compiler/Lexer/Keywords/KeywordEnd.cpp
        src/Compiler/Lexer/Keywords/KeywordEnd.h
        src/Compiler/Lexer/Keywords/KeywordPrimary.cpp
        src/Compiler/Lexer/Keywords/KeywordPrimary.h
        src/Compiler/Lexer/Keywords/KeywordString.cpp
        src/Compiler/Lexer/Keywords/KeywordString.h
        src/Compiler/Lexer/Keywords/KeywordInteger.cpp
        src/Compiler/Lexer/Keywords/KeywordInteger.h
        src/Compiler/Lexer/Keywords/KeywordBoolean.cpp
        src/Compiler/Lexer/Keywords/KeywordBoolean.h
        src/Compiler/Lexer/Keywords/KeywordDepends.cpp
        src/Compiler/Lexer/Keywords/KeywordDepends.h
        src/Compiler/Lexer/Keywords/KeywordNull.cpp
        src/Compiler/Lexer/Keywords/KeywordNull.h
        src/Compiler/Lexer/Keywords/Abstract/Observer.cpp
        src/Compiler/Lexer/Keywords/Abstract/Observer.h)
target_link_libraries(
        NekoDBMSTest
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(NekoDBMSTest)

