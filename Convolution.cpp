#include "Convolution.h"

Convolution::Convolution(int **kernel, int kw, int kh, int (*scaler)(int)):
m_kernel(kernel), m_kernelWidth(kw), m_kernelHeight(kh), m_scaler(scaler) {}

void Convolution::process(const Image& src, Image& dst) {

    // Iterate over each pixel in the source image
    for (unsigned int x = 0; x < src.getH() - m_kernelHeight + 1; ++x) {
        for (unsigned int y = 0; y < src.getW() - m_kernelWidth + 1; ++y) {
            int sum = 0;
            // Iterate over each element in the kernel
            for (int u = 0; u < m_kernelHeight; ++u) {
                for (int v = 0; v < m_kernelWidth; ++v) {
                    // Compute the corresponding pixel coordinates in the source image
                    int offsetX = x + u;
                    int offsetY = y + v;
                    // Check if the pixel coordinates are within the source image bounds
                    if (offsetX >= 0 && offsetX < src.getH() && offsetY >= 0 && offsetY < src.getW()) {
                        sum += m_kernel[u][v] * src.at(offsetX, offsetY);
                    }
                    
                }
            }
            // Store the result in the destination image
            dst.at  (x, y) = static_cast<unsigned char>(m_scaler(sum));
        }
    }
}

int Convolution::getKernelW() const {
    return m_kernelWidth;
}
int Convolution::getKernelH() const {
    return m_kernelHeight;
}