#ifndef ROMAN_NUMBER_TABLE_H
#define ROMAN_NUMBER_TABLE_H

#include <utility>
#include <vector>

class RomanNumberTable {
  public:
	RomanNumberTable();
	
    int GetValueFromSymbol(char symbol);
	
  private:
	void fillTable();
  
	typedef std::vector<std::pair <char, int> > SymbolNumberTable;
	SymbolNumberTable symbolNumberTable;
};

#endif
