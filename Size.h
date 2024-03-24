#pragma once
#include <istream>
#include <fstream>
#include <ostream>
#include <iostream>

class Size {
public:
	Size();
	Size(unsigned int width, unsigned int height);
	int getWidth() const;
	int getHeight() const;
	void setWidth(unsigned int width);
	void setHeight(unsigned int height);
	bool operator==(const Size& s) const;
	bool operator<(const Size& s) const;
	bool operator<=(const Size& s) const;
	bool operator>(const Size& s) const;
	bool operator>=(const Size& s) const;

private:
	unsigned int width;
	unsigned int height;
};