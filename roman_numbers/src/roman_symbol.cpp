#include "roman_symbol.hpp"

romanSymbol::romanSymbol(const char symbol) {
	if(symbolIsValid(symbol)) {
		_symbol = symbol;
	}
	else {
		// Throw!
	}
}

bool romanSymbol::symbolIsValid(const char symbol) {

}


