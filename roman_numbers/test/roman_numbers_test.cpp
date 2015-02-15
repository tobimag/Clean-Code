#include <gtest/gtest.h>
#include "roman_numbers.h"

TEST(RomanNumberTest, SingelRoman) {

	RomanNumbers romanNumbers;
	EXPECT_EQ(5, romanNumbers.ConvertFromRoman('V'));

}

TEST(RomanNumberTest, AdditonsOnly) {
	RomanNumbers romanNumbers;
	EXPECT_EQ(11, romanNumbers.ConvertFromRoman("XI"));
	EXPECT_EQ(1666, romanNumbers.ConvertFromRoman("MDCLXVI"));
	EXPECT_EQ(20, romanNumbers.ConvertFromRoman("XX"));
}

TEST(RomanNumberTest, SubtractiveOrder) {
	RomanNumbers romanNumbers;
	EXPECT_EQ(4, romanNumbers.ConvertFromRoman("IV"));
	EXPECT_EQ(8, romanNumbers.ConvertFromRoman("IIX"));
	EXPECT_EQ(1444 , romanNumbers.ConvertFromRoman("MCDXLIV"));
	EXPECT_EQ(800, romanNumbers.ConvertFromRoman("CCM"));
}


