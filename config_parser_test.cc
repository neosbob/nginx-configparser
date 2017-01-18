#include "gtest/gtest.h"
#include "config_parser.h"
#include <iostream>
using namespace std;


TEST(NginxConfigParserTest, SimpleConfig) {
  NginxConfigParser parser;
  NginxConfig out_config;

  bool success = parser.Parse("example_config", &out_config);

  EXPECT_TRUE(success);
}

class NginxConfigTest : public testing::Test {

    protected:
    bool Helper() {


    }

    NginxConfigParser parse;
    NginxConfig out_config_;


};

TEST_F(NginxConfigTest, ToString) {
    NginxConfigParser parser;
    NginxConfig out_config;

    bool success = parser.Parse("example_config", &out_config);

    std::string check = out_config.ToString();

    cout << check;

    ASSERT_EQ( check , check);

}

class NginxConfigParserTest : public testing::Test {

    protected:

    bool Helper() {


    }

    NginxConfigParser parse;
    NginxConfig out_config_;



};

TEST_F(NginxConfigParserTest, TokenTypeAsString) {
    

}

TEST_F(NginxConfigParserTest, ParseToken) {
    

}

TEST_F(NginxConfigParserTest, Parse) {
    

}

class NginxConfigStatementTest : public testing::Test {

    protected:

    bool Helper() {


    }

    NginxConfigParser parse;
    NginxConfig out_config_;



};

TEST_F(NginxConfigStatementTest, ToString2) {
    

}

/*
int main(int argc, char **argv) {
  //::testing::InitGoogleTest(&argc, argv);
  //return RUN_ALL_TESTS();
  
    NginxConfigParser parser;
    NginxConfig out_config;

    bool success = parser.Parse("example_config", &out_config);

    std::string check = out_config.ToString(5);

    cout << check;

    //EXPECT_STREQ( check , check);
}*/
