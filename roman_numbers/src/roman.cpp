#include "roman.hpp"

Roman::Roman() {
	_symbols = "";
}

Roman::Roman(const Roman& other)
: _symbols(other._symbols)
 {}

Roman::Roman(const std::string& symbols)
: _symbols(symbols)
 {}

Roman& Roman::operator=(const Roman& rhs) {
	_symbols = rhs._symbols;
	return *this;
}

Roman::operator std::string() {
	return _symbols;
}
