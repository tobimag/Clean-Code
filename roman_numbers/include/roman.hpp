#ifndef ROMAN_NUMBERS_H
#define ROMAN_NUMBERS_H

#include <string>

class Roman {
	public:
	Roman();
	Roman(const Roman&);
	Roman(const std::string&);	
	Roman(const char*);

	Roman& operator=(const Roman&);
	Roman& operator=(const char*);

	bool operator==(const Roman&) const;
	bool operator!=(const Roman&) const;
	bool operator>(const Roman&) const;
	bool operator<(const Roman&) const;

	bool operator==(unsigned int) const;
	bool operator!=(unsigned int) const;
	bool operator>(unsigned int) const;
	bool operator<(unsigned int) const;


	private:
	std::string _symbols;
	
	unsigned int toArabic() const;
	unsigned int toArabicHelper(const std::string&) const;
	unsigned int toArabicHelper(const char) const;
};

// String relation operators
bool operator==(const Roman&, const std::string&);
bool operator==(const std::string&, const Roman&);

bool operator!=(const Roman&, const std::string&);
bool operator!=(const std::string&, const Roman&);

// Integer relation operators
bool operator==(unsigned int, const Roman&);
bool operator>(unsigned int, const Roman&);
bool operator<(unsigned int, const Roman&);

#endif

