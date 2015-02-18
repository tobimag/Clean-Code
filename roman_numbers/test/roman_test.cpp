#include <gtest/gtest.h>

#define protected public
#include "roman.hpp"

TEST(RomanTest, DefaultConstructor) {
	Roman roman;
	EXPECT_EQ(roman.GetSymbols(), "");	
}

TEST(RomanTest, StringArgumentConstructor) {
	std::string romanSymbols = "XVI";
	Roman roman(romanSymbols);
	EXPECT_EQ(roman.GetSymbols(), romanSymbols);
}

TEST(RomanTest, CopyConstructor) {
	Roman roman1("XVI");
	Roman roman2(roman1);
	EXPECT_EQ(roman1.GetSymbols(), roman2.GetSymbols());
}
