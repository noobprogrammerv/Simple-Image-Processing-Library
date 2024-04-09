#include "DrawingModule.h"
#include <cmath>
#include <iostream>

float distance(Point P1, Point P2) {
	return sqrtf((P2.getX() - P1.getX()) * (P2.getX() - P1.getX()) + (P2.getY() - P1.getY()) * (P2.getY() - P1.getY()));
}

void DrawingModule::drawCircle(Image& img, Point center, int radius, unsigned char color) {
    int x = radius - 1;
    int y = 0;
    int dx = 1;
    int dy = 1;
    int err = dx - (radius << 1);

    while (x >= y) {
        img.at(center.getX() + x, center.getY() + y) = color;
        img.at(center.getX() + y, center.getY() + x) = color;
        img.at(center.getX() - y, center.getY() + x) = color;
        img.at(center.getX() - x, center.getY() + y) = color;
        img.at(center.getX() - x, center.getY() - y) = color;
        img.at(center.getX() - y, center.getY() - x) = color;
        img.at(center.getX() + y, center.getY() - x) = color;
        img.at(center.getX() + x, center.getY() - y) = color;

        if (err <= 0) {
            y++;
            err += dy;
            dy += 2;
        }
        if (err > 0) {
            x--;
            dx += 2;
            err += dx - (radius << 1);
        }
    }
}

void DrawingModule::drawLine(Image& img, Point p1, Point p2, unsigned char color) {
    int dx = abs(p2.getX() - p1.getX());
    int dy = abs(p2.getY() - p1.getY());
    int sx = (p1.getX() < p2.getX()) ? 1 : -1;
    int sy = (p1.getY() < p2.getY()) ? 1 : -1;
    int err = dx - dy;

    while (p1.getX() != p2.getX() || p1.getY() != p2.getY()) {
        img.at(p1.getX(), p1.getY()) = color;
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            p1.setX(p1.getX() + sx);
        }
        if (e2 < dx) {
            err += dx;
            p1.setY(p1.getY() + sy);
        }
    }
}

void DrawingModule::drawRectangle(Image& img, Rectangle r, unsigned char color) {
    Point tl = r.getTopLeft();
    Point br = r.getBottomRight();

    Point tr(br.getX(), tl.getY());
    Point bl(tl.getX(), br.getY());

    drawLine(img, tl, tr, color);
    drawLine(img, tr, br, color);
    drawLine(img, br, bl, color);
    drawLine(img, bl, tl, color);
}

void DrawingModule::drawRectangle(Image& img, Point tl, Point br, unsigned char color) {
	Rectangle r(tl, br);
	drawRectangle(img, r, color);
}