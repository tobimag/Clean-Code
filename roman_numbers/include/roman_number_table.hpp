#ifndef ROMAN_NUMBER_TABLE_HPP
#define ROMAN_NUMBER_TABLE_HPP

#include <utility>
#include <vector>

class RomanNumberTable {
  public:
	RomanNumberTable();
	
    unsigned int GetValueFromSymbol(char symbol);
	
  private:
	void fillTable();
  
	typedef std::vector<std::pair <char, unsigned int> > SymbolNumberTable;
	SymbolNumberTable symbolNumberTable;
};

#endif
