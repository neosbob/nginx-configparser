#include "gtest/gtest.h"
#include "config_parser.h"
#include <iostream>
#include <sstream>
using namespace std;

/*Main purpose of Unit tests are to check if
the functions behaves correctly.*/


TEST(NginxConfigParserTestx, SimpleConfig) {
  NginxConfigParser parser;
  NginxConfig out_config;

  bool success = parser.Parse("example_config", &out_config);

  EXPECT_TRUE(success);
}

class NginxConfigTest : public testing::Test {

    protected:

    NginxConfigParser parse;
    NginxConfig out_config_;


};

TEST_F(NginxConfigTest, ToString) {
    NginxConfigParser parser;
    NginxConfig out_config;

    bool success = parser.Parse("example_config", &out_config);

    std::string check = out_config.ToString();

    //cout << check;

    ASSERT_EQ( check , out_config.ToString());

}

class NginxConfigParserTest : public testing::Test {

    protected:

    bool Helper(const std::string config_string) {
      std::stringstream config_stream(config_string);
      return parse.Parse(&config_stream, &out_config);

    }

    NginxConfigParser parse;
    NginxConfig out_config;



};

TEST_F(NginxConfigParserTest, TokenTypeAsString) {
    EXPECT_EQ(1, Helper("foo \"bar\";"));
    EXPECT_EQ(1, out_config.statements_.size());

    EXPECT_EQ(2, out_config.statements_[0]->tokens_.size());

    EXPECT_EQ("foo", out_config.statements_[0]->tokens_[0]);

    EXPECT_EQ("\"bar\"", out_config.statements_[0]->tokens_[1]);

}

TEST_F(NginxConfigParserTest, Double_Semicolon) {
    EXPECT_FALSE(Helper("foo bar;;"));

}

TEST_F(NginxConfigParserTest, ExtraBracket) {
    EXPECT_EQ(1, Helper("server { listen 100; }"));

    EXPECT_NE(1, Helper("server { listen 100; }}"));

    EXPECT_NE(1, Helper("server {{ listen 100; }"));


    //Error here, For some reason not ending with a "}" passes
    EXPECT_NE(1, Helper("server { listen 100;"));

}

TEST_F(NginxConfigParserTest, Block_brackets) {
    EXPECT_EQ(1, Helper("server { listen 100; }"));

    EXPECT_EQ(1, out_config.statements_.size());

    EXPECT_NE(nullptr, out_config.statements_[0]->child_block_.get());

    EXPECT_EQ(2, out_config.statements_[0]->child_block_->statements_[0]->tokens_.size());

}

TEST_F(NginxConfigParserTest, Comment_etc) {
    EXPECT_NE(1, Helper(""));

    EXPECT_NE(1, Helper("# server { listen 100; }}"));

}

class NginxConfigStatementTest : public testing::Test {

    protected:

    NginxConfigParser parse;
    NginxConfig out_config_;

};

TEST_F(NginxConfigStatementTest, ToString2) {
    NginxConfigStatement statement;
    statement.tokens_.push_back("test");
    statement.tokens_.push_back("string");

    EXPECT_EQ(statement.ToString(0), "test string;\n");

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
