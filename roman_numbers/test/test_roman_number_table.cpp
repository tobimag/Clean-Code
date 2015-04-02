#include "../include/roman_number_table.hpp"

#include <gtest/gtest.h>

TEST(RomanNumberTableTest, GetAllValues) {

	RomanNumberTable romanNumberTable;
	EXPECT_EQ(1, romanNumberTable.GetValueFromSymbol('I'));
	EXPECT_EQ(5, romanNumberTable.GetValueFromSymbol('V'));
	EXPECT_EQ(10, romanNumberTable.GetValueFromSymbol('X'));
	EXPECT_EQ(50, romanNumberTable.GetValueFromSymbol('L'));
	EXPECT_EQ(100, romanNumberTable.GetValueFromSymbol('C'));
	EXPECT_EQ(500, romanNumberTable.GetValueFromSymbol('D'));
	EXPECT_EQ(1000, romanNumberTable.GetValueFromSymbol('M'));
	
}

TEST(RomanNumberTableTest, InvalidSymbol) {
	
	RomanNumberTable romanNumberTable;
	EXPECT_EQ(0, romanNumberTable.GetValueFromSymbol('A'));
}
