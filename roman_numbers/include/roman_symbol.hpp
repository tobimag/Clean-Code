#ifndef INCLUDE_ROMAN_SYMBOL_HPP_
#define INCLUDE_ROMAN_SYMBOL_HPP_

#include <vector>
#include <utility>

class romanSymbol {
public:
	romanSymbol(const char);

private:

	const char _symbol;
	unsigned int _value;

	bool symbolIsValid(const char);
};



#endif /* INCLUDE_ROMAN_SYMBOL_HPP_ */
