#pragma once
#include <istream>
#include <fstream>
#include <ostream>
#include <iostream>

class Size {
public:
	Size();
	Size(unsigned int width, unsigned int length);
	int getWidth() const;
	int getLength() const;
	void setWidth(unsigned int width);
	void setLength(unsigned int length);
	bool operator==(const Size& s) const;
	bool operator<(const Size& s) const;
	bool operator<=(const Size& s) const;
	bool operator>(const Size& s) const;
	bool operator>=(const Size& s) const;

private:
	unsigned int width;
	unsigned int length;
};