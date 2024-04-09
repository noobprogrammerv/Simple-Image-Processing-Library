#include "Rectangle.h"
#include <cmath>
#include <algorithm>


Rectangle::Rectangle() {
	this->x = 0;
	this->y = 0;
	this->width = 0;
	this->height = 0;
}

Rectangle::Rectangle(int x, int y, unsigned int width, unsigned int height) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

Rectangle::Rectangle(Point P1, Point P2) {
	unsigned int x, y, width, height;

	x = std::min(P1.getX(), P2.getX());
	y = std::max(P1.getY(), P2.getY());

	height = std::max(P1.getY(), P2.getY()) - std::min(P1.getY(), P2.getY());
	width = std::max(P1.getX(), P2.getX()) - std::min(P1.getX(), P2.getX());

	this->x = x;
	this->y = y;
	this->height = height;
	this->width = width;
}

Rectangle Rectangle::operator+(const Point& p) {
	Rectangle r;
	int x = (this->x = this->x + p.getX());
	int y = (this->y = this->y + p.getY());
	r.setX(x);
	r.setY(y);
	return r;
}

Rectangle Rectangle::operator-(const Point& p) {
	Rectangle r;
	int x = (this->x = this->x - p.getX());
	int y = (this->y = this->y - p.getY());
	r.setX(x);
	r.setY(y);
	return r;
}

int Rectangle::getX() const {
	return this->x;
}

int Rectangle::getY() const {
	return this->y;
}

int Rectangle::getW() const {
	return this->width;
}

int Rectangle::getH() const {
	return this->height;
}

void Rectangle::setX(int x) {
	this->x = x;
}

void Rectangle::setY(int y) {
	this->y = y;
}

void Rectangle::setW(unsigned int w) {
	this->width = w;
}
void Rectangle::setH(unsigned int h) {
	this->height = h;
}

Rectangle Rectangle::operator&(const Rectangle& r) const {
	int x1, x2, y1, y2;
	int rw = r.getW();
	int rh = r.getH();
	int tw = width;
	int th = height;
	x1 = std::max(this->x, r.getX());
	x2 = std::min(this->x + tw, r.getX() + rw);
	y1 = std::max(this->y, r.y);
	y2 = std::min(this->y + th, r.y + rh);

	if (x1 < x2 && y1 < y2) {
		return Rectangle(x1, y1, x2 - x1, y2 - y1);
	}
	return Rectangle();
}
Rectangle Rectangle::operator|(const Rectangle & r) const {
	int x1, x2, y1, y2;
	int rw = r.getW();
	int rh = r.getH();
	int tw = width;
	int th = height;
	x1 = std::min(this->x, r.x);
	x2 = std::max(this->x + tw, r.x + rw);
	y1 = std::min(this->y, r.y);
	y2 = std::max(this->y + th, r.y + rh);

	return Rectangle(x1, y1, x2 - x1, y2 - y1);
}

Rectangle& Rectangle::operator=(const Rectangle& r) {
	this->x = r.x;
	this->y = r.y;
	this->width = r.width;
	this->height = r.height;
	return *this;
}

Point Rectangle::getTopLeft() const {
	return Point(x, y);
}

Point Rectangle::getBottomRight() const {
	return Point(x + width, y + height);
}