#include <gtest/gtest.h>

#define protected public
#include "roman.hpp"

TEST(RomanTest, DefaultConstructor) {
	Roman roman;
	EXPECT_EQ("", (std::string)roman);
}

TEST(RomanTest, StringArgumentConstructor) {
	std::string romanSymbols = "XVI";
	Roman roman(romanSymbols);
	EXPECT_EQ(romanSymbols, (std::string)roman);
}

TEST(RomanTest, CopyConstructor) {
	Roman roman1("XVI");
	Roman roman2(roman1);
	EXPECT_EQ((std::string) roman1, (std::string)roman2);

}
