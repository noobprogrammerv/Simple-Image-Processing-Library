#pragma once
#include "Point.h"
#include <iostream>
#include <algorithm>


class Rectangle {
public:
	friend class Point;

	Rectangle();
	Rectangle(int x, int y, unsigned int width, unsigned int height);
	Rectangle(Point p1, Point p2);
	int getX() const;
	int getY() const;
	int getW() const;
	int getH() const;
	void setX(int x);
	void setY(int y);
	void setW(unsigned int w);
	void setH(unsigned int h);
	Rectangle operator+(const Point& p);
	Rectangle operator-(const Point& p);
	Rectangle operator&(const Rectangle& r) const;
	Rectangle operator|(const Rectangle& r) const;
	Rectangle& operator=(const Rectangle& r);
	Point getTopLeft() const;
	Point getBottomRight() const;

private:
	int x;
	int y;
	unsigned int width;
	unsigned int height;

};

