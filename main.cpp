#include <iostream>
#include "Rectangle.h"


int main() {
    /*Rectangle r1(1,1,3,2);
    Rectangle r2(3,2,3,2);
    Rectangle result;
    result = r1 | r2;

    std::cout << result.getX() << ' ' << result.getY() << ' ' << result.getW() << ' ' << result.getH();*/
    /*char x[] = { "Vs ad" };
    char digit = ' ';
    char* found = std::find(std::begin(x), std::end(x), digit);
    int pos = found - x;
    if (found != std::end(x))
        std::cout << "Found at position " << pos;
    else 
        std::cout << "NOT";*/
    char x = '7';
    int nr = static_cast<int>(x - '0');
    std::cout << nr;

    return 0;
}
