#include <fstream>
#include <iostream>

#include "gtest/gtest.h"

namespace {

std::string ReadFile(const std::string& path) {
    std::ifstream fp(path);
    std::stringstream buf;
    buf << fp.rdbuf();
    return buf.str();
}

}  // namespace

TEST(RulesM4, ExpansionTest) {
    const char EXPECT[] = R"(Hello, world!
)";
    const auto got = ReadFile("./tests/expansion_test");
    ASSERT_EQ(got, EXPECT);
}

TEST(RulesM4, RecoveryTest) {
    const char EXPECT[] = R"(from template_1: Hello, world!
from template_2: Hello, world (again)!
)";
    const auto got = ReadFile("./tests/template_test");
    ASSERT_EQ(got, EXPECT);
}
