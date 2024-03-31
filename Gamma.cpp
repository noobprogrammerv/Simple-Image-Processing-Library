#include "Gamma.h"

Gamma::Gamma() {
	gamma = 1;
}

Gamma::Gamma(double gamma) {
	this->gamma = gamma;
}
void Gamma::process(const Image& src, Image& dst) {
	for (int i = 0; i < dst.getH(); ++i) {
		for (int j = 0; j < dst.getW(); ++j) {
			int value = std::round(std::pow(src.at(i, j), gamma));
			if (value > 255) {
				dst.at(i, j) = 255;
			}
			else if (value < 0) {
				dst.at(i, j) = 0;
			}
			else {
				dst.at(i, j) = value;
			}

		}
	}
}