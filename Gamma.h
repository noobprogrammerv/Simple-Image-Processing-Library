#pragma once
#include "ImageProcessing.h"

class Gamma : public ImageProcessing {
public:
	Gamma();
	Gamma(double gamma);
	void process(const Image& src, Image& dst) override;

private:
	double gamma;
};	

