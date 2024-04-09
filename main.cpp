#include <iostream>
#include "Image.h"
#include "BrightnessAndContrast.h"
#include "Convolution.h"
#include "DrawingModule.h"
#include <fstream>

int f(int x) {
    return x % 255;
}


int main() {
    
    /*Image img;
    std::ifstream fin("C:\\Users\\Alex\\source\\repos\\1. Anul 1\\OOP\\extra2\\extra2\\img.txt");
    fin >> img;
    std::ofstream fout("C:\\Users\\Alex\\source\\repos\\1. Anul 1\\OOP\\extra2\\extra2\\imgOut.txt");
    fout << img;*/

    /*Image img;
    img.load("C:\\Users\\Alex\\source\\repos\\1. Anul 1\\OOP\\extra2\\extra2\\img.txt");
    BrightnessAndContrast bc(10, 0);
    Image dest(img.getW(), img.getH());
    bc.process(img, dest);
    dest.save("C:\\Users\\Alex\\source\\repos\\1. Anul 1\\OOP\\extra2\\extra2\\imgOut.txt");*/


    //CONVOLUTION TEST
    /*
    int** mat;
    mat = new int* [3];
    for (int i = 0; i < 3; ++i) {
        mat[i] = new int[3];
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            mat[i][j] = 1;
        }
    }
    mat[0][1] = 0;
    mat[1][0] = 0;
    mat[1][2] = 0, mat[2][1] = 0;
    //convolution
    Image img;
    std::ifstream fin("C:\\Users\\Alex\\source\\repos\\1. Anul 1\\OOP\\extra2\\extra2\\img.txt");
    fin >> img;
    Convolution cv(mat, 3, 3, f);
    Image imgN(img.getW() - cv.getKernelW() + 1, img.getH() - cv.getKernelH() + 1, img.getm_scale());
    cv.process(img, imgN);
    imgN.save("C:\\Users\\Alex\\source\\repos\\1. Anul 1\\OOP\\extra2\\extra2\\imgOut2.txt");
    */
    //CONVOLUTION TEST

    //RECTANGLE TEST
    /*Image img;
    std::ifstream fin("C:\\Users\\Alex\\source\\repos\\1. Anul 1\\OOP\\extra2\\extra2\\img.txt");
    fin >> img;
    fin.close();
    Point center(3, 3);
    int radius = 2;
    unsigned char color = 255;
    DrawingModule dm;
    Rectangle rect(3,3,2,2);
    dm.drawRectangle(img, rect, color);
    img.save("output_image.txt");*/
    //RECTANGLE TEST

    //LINE TEST
    /*Image img;
    std::ifstream fin("C:\\Users\\Alex\\source\\repos\\1. Anul 1\\OOP\\extra2\\extra2\\img.txt");
    fin >> img;
    fin.close();
    Point p1(2, 2);
    Point p2(2, 9);
    unsigned char color = 255;
    DrawingModule dm;
    dm.drawLine(img, p1, p2, color);
    img.save("output_image.txt");*/
    //LINE TEST

    //CIRCLE TEST
    /*Image img;
    std::ifstream fin("C:\\Users\\Alex\\source\\repos\\1. Anul 1\\OOP\\extra2\\extra2\\img.txt");
    fin >> img;
    fin.close();
    Point p(3, 3);
    unsigned int radius = 3;
    unsigned char color = 255;
    DrawingModule dm;
    dm.drawCircle(img, p, radius, color);
    img.save("output_image.txt");*/
    //CIRCLE TEST
















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
