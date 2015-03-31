#include "roman.hpp"

#include "roman_number_table.hpp"

Roman::Roman() {
	_symbols = "";
}

Roman::Roman(const Roman& other)
: _symbols(other._symbols)
 {}

Roman& Roman::operator=(const Roman& rhs) {
	if(*this != rhs) {
		_symbols = rhs._symbols;
	}
	return *this;
}

Roman& Roman::operator=(const char* rhs) {
	_symbols = rhs;
	return *this;
}

Roman::Roman(const std::string& symbols)
: _symbols(symbols)
 {}

Roman::Roman(const char* symbols)
: _symbols(symbols)
{}

bool Roman::operator==(const Roman& rhs) const {
	return _symbols == rhs._symbols;
}

bool Roman::operator!=(const Roman& rhs) const {
	return _symbols != rhs._symbols;
}

bool Roman::operator==(unsigned int rhs) const {
	return toArabic() == rhs;
}

bool Roman::operator!=(unsigned int rhs) const {
	return toArabic() != rhs;
}

bool Roman::operator>(unsigned int rhs) const {
	return toArabic() > rhs;
}

bool Roman::operator<(unsigned int rhs) const {
	return toArabic() < rhs;
}

bool Roman::operator>(const Roman& rhs) const {
	return toArabic() > rhs;
}
bool Roman::operator<(const Roman& rhs) const {
	return toArabic() < rhs;
}

unsigned int Roman::toArabic() const {
	return toArabicHelper(_symbols);
}

unsigned int Roman::toArabicHelper(const std::string& romanNumber) const {
	const char firstSymbol = romanNumber.front();
	const std::string tail = romanNumber.substr(1);
	if(tail.empty()) {
		return toArabicHelper(firstSymbol);
	}
	unsigned int subStringLength = 0;
	for(char symbol : tail) {
		++subStringLength;
		if(toArabicHelper(firstSymbol) < toArabicHelper(symbol)) {
			return -toArabicHelper(romanNumber.substr(0, subStringLength)) +
					toArabicHelper(romanNumber.substr(subStringLength));
		}
	}
	return toArabicHelper(firstSymbol) + toArabicHelper(tail);
}

unsigned int Roman::toArabicHelper(const char romanSymbol) const {
	RomanNumberTable romanNumberTable;
	return romanNumberTable.GetValueFromSymbol(romanSymbol);
}

bool operator==(const Roman& lhs, const std::string& rhs) {
	return lhs == Roman(rhs);
}

bool operator==(const std::string& lhs, const Roman& rhs) {
	return Roman(lhs) == rhs;
}

bool operator!=(const Roman& lhs, const std::string& rhs) {
	return lhs != Roman(rhs);
}

bool operator!=(const std::string& lhs, const Roman& rhs) {
	return Roman(lhs) != rhs;
}

bool operator==(unsigned int lhs, const Roman& rhs) {
	return rhs.operator==(lhs);
}

bool operator>(unsigned int lhs, const Roman& rhs) {
	return rhs.operator<(lhs);
}

bool operator<(unsigned int lhs, const Roman& rhs) {
	return !rhs.operator<(lhs);
}
