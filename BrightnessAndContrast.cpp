#include "BrightnessAndContrast.h"

BrightnessAndContrast::BrightnessAndContrast() {
	alpha = 1;
	beta = 0;
}

BrightnessAndContrast::BrightnessAndContrast(double a, double b) {
	alpha = a;
	beta = b;
}

void BrightnessAndContrast::process(const Image& src, Image& dst) {
	for (int i = 0; i < dst.getH(); ++i) {
		for (int j = 0; j < dst.getW(); ++j) {
			int value = std::round(alpha * src.at(i, j) + beta);
			if (value > 255) {
				dst.at(i, j) = 255;
			} else if (value < 0) {
				dst.at(i, j) = 0;
			} else {
				dst.at(i, j) = value;
			}
		}
	}
	
}