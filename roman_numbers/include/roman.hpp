#ifndef ROMAN_NUMBERS_H
#define ROMAN_NUMBERS_H

#include <string>

class Roman {
	public:
	Roman();
	Roman(const std::string&);	
	Roman(const Roman&);	
	Roman& operator=(const Roman&);
	
	protected:
	std::string GetSymbols();	
	
	private:
	std::string _symbols;
	
	swap(const Roman&);
	
};

#endif
