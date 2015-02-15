#include "roman_numbers.h"

#include "roman_number_table.h"

RomanNumbers::RomanNumbers() {	
}

int RomanNumbers::ConvertFromRoman(char romanNumber) {
	return romanNumberTable.GetValueFromSymbol(romanNumber);
} 

int RomanNumbers::ConvertFromRoman(std::string romanNumber) {
	char thisSymbol = romanNumber.front();
	std::string tail = romanNumber.substr(1);
	if(tail.empty()) {
		return ConvertFromRoman(thisSymbol);
	}
	int subStringLength = 0;
	for(char symbol : tail) {
		++subStringLength;		
		if(ConvertFromRoman(symbol) > ConvertFromRoman(thisSymbol)) {
			return -ConvertFromRoman(romanNumber.substr(0, subStringLength)) + 
				   ConvertFromRoman(romanNumber.substr(subStringLength));
		}
	
	}
	return ConvertFromRoman(thisSymbol) + ConvertFromRoman(tail);
}
