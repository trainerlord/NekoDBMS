//
// Created by Daniel on 10/26/23.
//

#include <gtest/gtest.h>
#include "../../src/Gateways/SourceCodeGateway.h"

#define EXAMPLE_SOURCE "@Schema NekoSquare {\n    @Table Accounts {\n        @Primary @String email_address;\n\t    @String password;\n    }\n    @Table Tokens {\n\t@Primary @Depends(Accounts.email_address, \"fk_accounts\") @String email_address;\n\t@String token;\n    }\n}\n\n"

TEST(TestSourceCodeGateway, TestReadExampleFile) {
    std::string file = SourceCodeGateway::readSourceFile("../example.dbms");
    EXPECT_EQ(EXAMPLE_SOURCE, file);
}