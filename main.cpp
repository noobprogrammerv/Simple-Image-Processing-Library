#include <iostream>
#include "Image.h"
#include "BrightnessAndContrast.h"
#include <fstream>


int main() {
    Image img;
    std::ifstream fin("C:\\Users\\Alex\\source\\repos\\1. Anul 1\\OOP\\extra2\\extra2\\img.txt");
    fin >> img;
    std::ofstream fout("C:\\Users\\Alex\\source\\repos\\1. Anul 1\\OOP\\extra2\\extra2\\imgOut.txt");
    fout << img;

    /*Image img;
    img.load("C:\\Users\\Alex\\source\\repos\\1. Anul 1\\OOP\\extra2\\extra2\\img.txt");
    BrightnessAndContrast bc(10, 0);
    Image dest(img.getW(), img.getH());
    bc.process(img, dest);
    dest.save("C:\\Users\\Alex\\source\\repos\\1. Anul 1\\OOP\\extra2\\extra2\\imgOut.txt");*/













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
    /*char x = '7';
    int nr = static_cast<int>(x - '0');
    std::cout << nr;*/

    return 0;
}
