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
        src/Compiler/Parser.cpp
        src/Compiler/Parser.h src/Compiler/Adapters/AbstractComplier.cpp src/Compiler/Adapters/AbstractComplier.h src/Compiler/Adapters/PostgreSQLComplier.cpp src/Compiler/Adapters/PostgreSQLComplier.h
        src/Compiler/Lexer/Keywords/Abstract/BasicKeyword.h
        src/Compiler/Lexer/Keywords/Abstract/ObserverKeyword.cpp
        src/Compiler/Lexer/Keywords/Abstract/ObserverKeyword.h
        src/Compiler/Lexer/Keywords/Constructors/KeywordSchema.cpp
        src/Compiler/Lexer/Keywords/Constructors/KeywordSchema.h
        src/Compiler/Lexer/Keywords/Abstract/ObserverKeyword.cpp
        src/Compiler/Lexer/Keywords/Constructors/KeywordTable.cpp
        src/Compiler/Lexer/Keywords/Constructors/KeywordTable.h
        src/Compiler/Lexer/Keywords/Operations/KeywordEnd.cpp
        src/Compiler/Lexer/Keywords/Operations/KeywordEnd.h
        src/Compiler/Lexer/Keywords/Types/KeywordPrimary.cpp
        src/Compiler/Lexer/Keywords/Types/KeywordPrimary.h
        src/Compiler/Lexer/Keywords/Types/KeywordString.cpp
        src/Compiler/Lexer/Keywords/Types/KeywordString.h
        src/Compiler/Lexer/Keywords/Types/KeywordInteger.cpp
        src/Compiler/Lexer/Keywords/Types/KeywordInteger.h
        src/Compiler/Lexer/Keywords/Types/KeywordBoolean.cpp
        src/Compiler/Lexer/Keywords/Types/KeywordBoolean.h
        src/Compiler/Lexer/Keywords/Operations/KeywordDepends.cpp
        src/Compiler/Lexer/Keywords/Operations/KeywordDepends.h
        src/Compiler/Lexer/Keywords/Types/KeywordNull.cpp
        src/Compiler/Lexer/Keywords/Types/KeywordNull.h
        src/Compiler/Lexer/Keywords/Abstract/Observer.cpp
        src/Compiler/Lexer/Keywords/Abstract/Observer.h
        src/Compiler/Lexer/KeywordFactory.cpp src/Compiler/Lexer/KeywordFactory.h src/Compiler/Adapters/SchemaInstructions.h
        src/Compiler/Lexer/Keywords/Operations/KeywordReturn.cpp
        src/Compiler/Lexer/Keywords/Operations/KeywordReturn.h
        src/Compiler/Lexer/Keywords/Operations/KeywordLet.cpp
        src/Compiler/Lexer/Keywords/Operations/KeywordLet.h
        src/Compiler/Lexer/Keywords/Constructors/KeywordFunction.cpp
        src/Compiler/Lexer/Keywords/Constructors/KeywordFunction.h
        src/Compiler/Lexer/Keywords/Operations/OperationAssign.cpp
        src/Compiler/Lexer/Keywords/Operations/OperationAssign.h
        src/Compiler/Lexer/Keywords/Operations/DataOperations.cpp
        src/Compiler/Lexer/Keywords/Operations/DataOperations.h
        src/Compiler/Lexer/Keywords/Operations/DataOperations/OperationSelect.cpp
        src/Compiler/Lexer/Keywords/Operations/DataOperations/OperationSelect.h
        src/Compiler/Lexer/Keywords/Operations/DataOperations/OperationJoin.cpp
        src/Compiler/Lexer/Keywords/Operations/DataOperations/OperationJoin.h)

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
        src/Compiler/Parser.cpp
        src/Compiler/Parser.h
        src/Compiler/Adapters/PostgreSQLComplier.cpp
        src/Compiler/Adapters/PostgreSQLComplier.h
        src/Compiler/Adapters/AbstractComplier.cpp
        src/Compiler/Adapters/AbstractComplier.h
        test/Compiler/TestParser.cpp
        test/Compiler/Adapters/TestPostgreSQLComplier.cpp
        src/Compiler/Lexer/Keywords/Abstract/BasicKeyword.h
        src/Compiler/Lexer/Keywords/Abstract/ObserverKeyword.cpp
        src/Compiler/Lexer/Keywords/Abstract/ObserverKeyword.h
        src/Compiler/Lexer/Keywords/Constructors/KeywordSchema.cpp
        src/Compiler/Lexer/Keywords/Constructors/KeywordSchema.h
        src/Compiler/Lexer/Keywords/Abstract/ObserverKeyword.cpp
        src/Compiler/Lexer/Keywords/Constructors/KeywordTable.cpp
        src/Compiler/Lexer/Keywords/Constructors/KeywordTable.h
        src/Compiler/Lexer/Keywords/Operations/KeywordEnd.cpp
        src/Compiler/Lexer/Keywords/Operations/KeywordEnd.h
        src/Compiler/Lexer/Keywords/Types/KeywordPrimary.cpp
        src/Compiler/Lexer/Keywords/Types/KeywordPrimary.h
        src/Compiler/Lexer/Keywords/Types/KeywordString.cpp
        src/Compiler/Lexer/Keywords/Types/KeywordString.h
        src/Compiler/Lexer/Keywords/Types/KeywordInteger.cpp
        src/Compiler/Lexer/Keywords/Types/KeywordInteger.h
        src/Compiler/Lexer/Keywords/Types/KeywordBoolean.cpp
        src/Compiler/Lexer/Keywords/Types/KeywordBoolean.h
        src/Compiler/Lexer/Keywords/Operations/KeywordDepends.cpp
        src/Compiler/Lexer/Keywords/Operations/KeywordDepends.h
        src/Compiler/Lexer/Keywords/Types/KeywordNull.cpp
        src/Compiler/Lexer/Keywords/Types/KeywordNull.h
        src/Compiler/Lexer/Keywords/Abstract/Observer.cpp
        src/Compiler/Lexer/Keywords/Abstract/Observer.h src/Compiler/Lexer/KeywordFactory.cpp src/Compiler/Lexer/KeywordFactory.h src/Compiler/Adapters/SchemaInstructions.h
        test/Compiler/Lexer/Keywords/Operations/TestKeywordReturn.cpp
        src/Compiler/Lexer/Keywords/Operations/KeywordReturn.cpp
        src/Compiler/Lexer/Keywords/Operations/KeywordReturn.h
        src/Compiler/Lexer/Keywords/Operations/KeywordLet.cpp
        src/Compiler/Lexer/Keywords/Operations/KeywordLet.h
        test/Compiler/Lexer/Keywords/Operations/TestKeywordLet.cpp
        src/Compiler/Lexer/Keywords/Constructors/KeywordFunction.cpp
        src/Compiler/Lexer/Keywords/Constructors/KeywordFunction.h
        test/Compiler/Lexer/Keywords/Constructors/TestKeywordFunction.cpp
        src/Compiler/Lexer/Keywords/Operations/OperationAssign.cpp
        src/Compiler/Lexer/Keywords/Operations/OperationAssign.h
        src/Compiler/Lexer/Keywords/Operations/DataOperations.cpp
        src/Compiler/Lexer/Keywords/Operations/DataOperations.h
        src/Compiler/Lexer/Keywords/Operations/DataOperations/OperationSelect.cpp
        src/Compiler/Lexer/Keywords/Operations/DataOperations/OperationSelect.h
        src/Compiler/Lexer/Keywords/Operations/DataOperations/OperationJoin.cpp
        src/Compiler/Lexer/Keywords/Operations/DataOperations/OperationJoin.h)
target_link_libraries(
        NekoDBMSTest
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(NekoDBMSTest)

