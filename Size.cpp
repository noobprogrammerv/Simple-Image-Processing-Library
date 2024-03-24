#include "Size.h"

Size::Size() {
	this->length = 0;
	this->width = 0;
}

Size::Size(unsigned int width, unsigned int length) {
	this->width = width;
	this->length = length;
}

int Size::getWidth() const {
	return this->width;
}

int Size::getLength() const {
	return this->length;
}

void Size::setWidth(unsigned int width) {
	this->width = width;
}

void Size::setLength(unsigned int length) {
	this->length = length;
}

bool Size::operator==(const Size& s) const {
	if (this->width == s.width && this->length == s.length) {
		return true;
	}
	return false;
}

bool Size::operator<(const Size& s) const {
	if (this->width < s.width && this->length < s.length) {
		return true;
	}
	return false;
}

bool Size::operator<=(const Size& s) const {
	if (this->width <= s.width && this->length <= s.length) {
		return true;
	}
	return false;
}
bool Size::operator>(const Size& s) const {
	if (this->width > s.width && this->length > s.length) {
		return true;
	}
	return false;
}
bool Size::operator>=(const Size& s) const {
	if (this->width >= s.width && this->length >= s.length) {
		return true;
	}
	return false;
}