#include "roman_number_table.h"

RomanNumberTable::RomanNumberTable()
  : symbolNumberTable() {
	fillTable();	
	}

void RomanNumberTable::fillTable() {
	symbolNumberTable = {std::make_pair('I',1), 
						 std::make_pair('V',5),
						 std::make_pair('X',10),
						 std::make_pair('L',50),
						 std::make_pair('C',100),
						 std::make_pair('D',500),
						 std::make_pair('M',1000)};
}

int RomanNumberTable::GetValueFromSymbol(char romanNumber) {
	for(SymbolNumberTable::const_iterator it = symbolNumberTable.begin(); 
		it != symbolNumberTable.end(); ++it) {
		if(it->first == romanNumber) {
			return it->second;
		}
	}
	return 0;
} 
