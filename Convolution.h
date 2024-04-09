#pragma once
#include "ImageProcessing.h"

class Convolution : public ImageProcessing {
public:
	Convolution(int** kernel, int m_kernelWidth, int m_kernelHeight, int (*scaler)(int));
	void process(const Image& src, Image& dst) override;
	int getKernelW() const;
	int getKernelH() const;
private:
	int (*m_scaler)(int);
	int** m_kernel;
	int m_kernelWidth;
	int m_kernelHeight;
	//pointer to funct to scale
};

