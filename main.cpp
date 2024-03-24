#include <iostream>
#include "Rectangle.h"


int main() {
    Rectangle r1(1,1,3,2);
    Rectangle r2(3,2,3,2);
    Rectangle result;
    result = r1 | r2;
    
    std::cout << result.getX() << ' ' << result.getY() << ' ' << result.getW() << ' ' << result.getH();

    return 0;
}
