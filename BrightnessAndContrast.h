#pragma once
#include "ImageProcessing.h"

class BrightnessAndContrast : public ImageProcessing {
public:
	BrightnessAndContrast();
	BrightnessAndContrast(double alpha, double beta);
	void process(const Image& src, Image& dst) override;

private:
	double alpha;
	double beta;
};
