#pragma once
#include "ImageProcessing.h"

class Convolusion : public ImageProcessing {
public:
	void process(const Image& src, Image& dst) override;

	
};

