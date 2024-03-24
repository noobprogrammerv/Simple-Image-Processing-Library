#include "Size.h"

Size::Size() {
	this->height = 0;
	this->width = 0;
}

Size::Size(unsigned int width, unsigned int length) {
	this->width = width;
	this->height = length;
}

int Size::getWidth() const {
	return this->width;
}

int Size::getHeight() const {
	return this->height;
}

void Size::setWidth(unsigned int width) {
	this->width = width;
}

void Size::setHeight(unsigned int length) {
	this->height = length;
}

bool Size::operator==(const Size& s) const {
	if (this->width == s.width && this->height == s.height) {
		return true;
	}
	return false;
}

bool Size::operator<(const Size& s) const {
	if (this->width < s.width && this->height < s.height) {
		return true;
	}
	return false;
}

bool Size::operator<=(const Size& s) const {
	if (this->width <= s.width && this->height <= s.height) {
		return true;
	}
	return false;
}
bool Size::operator>(const Size& s) const {
	if (this->width > s.width && this->height > s.height) {
		return true;
	}
	return false;
}
bool Size::operator>=(const Size& s) const {
	if (this->width >= s.width && this->height >= s.height) {
		return true;
	}
	return false;
}