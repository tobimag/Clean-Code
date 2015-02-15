#ifndef ROMAN_NUMBERS_H
#define ROMAN_NUMBERS_H

#include <string>

#include "roman_number_table.h"

class RomanNumbers {
  public:
    RomanNumbers();
  
	int ConvertFromRoman(char romanNumber);
	int ConvertFromRoman(std::string romanNumber);
  
  private:
	RomanNumberTable romanNumberTable;
};

#endif

