#include <gtest/gtest.h>

#include "roman.hpp"

TEST(RomanTest, DefaultConstructor) {
	Roman roman;
	EXPECT_EQ("", roman);
}

TEST(RomanTest, StringArgumentConstructor) {
	std::string romanSymbols = "XVI";
	Roman roman(romanSymbols);
	EXPECT_EQ(romanSymbols, roman);
}

TEST(RomanTest, CopyConstructor) {
	Roman roman1("XVI");
	Roman roman2(roman1);
	EXPECT_EQ(roman1, roman2);
}

TEST(RomanTest, SingelRoman) {
	Roman five = "V";
	EXPECT_EQ(5, five);
}

TEST(RomanTest, AdditonsOnly) {
	Roman eleven = "XI";
	Roman oneThousandSixhundredSixtySix = "MDCLXVI";
	Roman twenty = "XX";
	EXPECT_EQ(11, eleven);
	EXPECT_EQ(1666, oneThousandSixhundredSixtySix);
	EXPECT_EQ(20, twenty);
}

TEST(RomanTest, SubtractiveOrder) {
	Roman four = "IV";
	Roman eight = "IIX";
	Roman oneThousandFourHundredForityFour = "MCDXLIV";
	Roman eightHundred = "CCM";
	EXPECT_EQ(4, four);
	EXPECT_EQ(8, eight);
	EXPECT_EQ(1444 , oneThousandFourHundredForityFour);
	EXPECT_EQ(800, eightHundred);
}
