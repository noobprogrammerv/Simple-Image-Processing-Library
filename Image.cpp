#include "Image.h"


Image::Image() {
	m_data = nullptr;
	m_width = 0;
	m_height = 0;
}

Image::Image(unsigned int width, unsigned int height) {
	this->m_width = width;
	this->m_height = height;
	m_data = new unsigned char* [height];
	for (int i = 0; i < height; ++i) {
		m_data[i] = new unsigned char[width];
	}
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			m_data[i][j] = 0;
		}
	}
}

Image::Image(const Image& other) {
	m_height = other.getH();//schimb getH() etc
	m_width = other.getW();
	m_data = new unsigned char* [other.getH()];
	for (int i = 0; i < other.getH(); ++i) {
		m_data[i] = new unsigned char[other.getW()];
	}
	for (int i = 0; i < other.getH(); ++i) {
		for (int j = 0; j < other.getW(); ++j) {
			m_data[i][j] = other.m_data[i][j];
		}
	}
}

Image::~Image() {
	release();
}

Image& Image::operator=(const Image& other) {
	if (this == &other)
		throw std::exception();
	this->release();
	m_width = other.m_width;
	m_height = other.m_height;
	m_data = new unsigned char* [other.m_width];
	for (int i = 0; i < m_width; ++i) {
		m_data[i] = new unsigned char[other.m_height];
	}
	for (int i = 0; i < other.m_height; ++i) {
		for (int j = 0; j < other.m_width; ++j) {
			m_data[i][j] = other.m_data[i][j];
		}
	}
	return *this;
}

void Image::release() {
	if (m_data != nullptr) {
		for (int i = 0; i < getH(); ++i) {
			delete[] this->m_data[i];
		}
		delete[] m_data;
		m_data = nullptr;
		m_width = 0;
		m_height = 0;
	}
}

unsigned int Image::getW() const {
	return this->m_width;
}

unsigned int Image::getH() const {
	return this->m_height;
}

void Image::setW(unsigned int height) {
	this->m_height = height;
}
void Image::setH(unsigned int width) {
	this->m_width = width;
}

Size Image::size() const {
	return Size(m_width, m_height);
}

bool Image::isEmpty() const {
	return (m_data == nullptr && m_width == 0 && m_height == 0);
}

std::ostream& operator<<(std::ostream& os, const Image& dt) {
	os << "P2\n#Simple pgm image example\n" << dt.m_width << ' ' << dt.m_height << "\n255\n";
	for (int i = 0; i < dt.m_height; ++i) {
		for (int j = 0; j < dt.m_width; ++j) {
			os << static_cast<int> (dt.m_data[i][j]) << ' ';
		}
		os << '\n';
	}
	return os;
}

std::istream& operator>>(std::istream& is, Image& dt) {
	char text[1000];
	is.getline(text, 1000);//P2
	if (strcmp(text, "P2")) {
		std::cout << "Magic number must be P2!";
		return is;
	}
	is.getline(text, 1000);//# comment
	if (text[0] != '#') {
		std::cout << "Comment line is missing!";
		return is;
	}
	//width height
	unsigned int width, height;
	is >> width >> height;
	if (width == 0 || height == 0) {
		std::cout << "Height and width must be greater than 0!";
		return is;
	}
	//255 pixel value
	unsigned int maxValue;
	is >> maxValue;
	dt.m_width = width;
	dt.m_height = height;
	dt.m_data = new unsigned char* [height];
	for (int i = 0; i < height; ++i)
		dt.m_data[i] = new unsigned char[width];
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			unsigned int pixel;
			is >> pixel;
			dt.m_data[i][j] = pixel;
		}
	}
	return is;
}

bool Image::load(std::string imagePath) {

	std::ifstream file(imagePath);
	if (!file.is_open()) {
		std::cout << "Error opening file!";
		return false;
	}
	file >> *this;
	file.close();
	return true;
}

bool Image::save(std::string imagePath) const {
	std::ofstream file(imagePath);
	if (!file.is_open()) {
		std::cout << "Error opening file!" << '\n';
		return false;
	}
	file << *this;
	file.close();
	return true;
}

Image Image::zeros(unsigned int width, unsigned int height) {
	Image img(width, height);
	return img;
}
Image Image::ones(unsigned int width, unsigned int height) {
	Image img(width, height);
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			img.m_data[i][j] = 1;
		}
	}
	return img;
}

unsigned int Image::width() const {
	return m_width;
}

unsigned int Image::height() const {
	return m_height;
}

unsigned char& Image::at(unsigned int x, unsigned int y) {
	if (x >= m_height || y >= m_width)
		throw std::exception();
	return m_data[x][y];
}

unsigned char& Image::at(Point pt) {
	if (pt.getX() >= m_height || pt.getY() >= m_width)
		throw std::exception();
	return m_data[pt.getX()][pt.getY()];
}

Image Image::operator+(const Image& image) {
	if (size() < image.size())
		throw std::exception();
	Image result(m_width, m_height);
	for (int i = 0; i < m_width; ++i) {
		for (int j = 0; j < m_height; ++j) {
			result.m_data[i][j] = m_data[i][j] + image.m_data[i][j];
		}
	}
	return result;
}

Image Image::operator-(const Image& image) {
	if (size() < image.size())
		throw std::exception();
	Image result(m_width, m_height);
	for (int i = 0; i < m_width; ++i) {
		for (int j = 0; j < m_height; ++j) {
			result.m_data[i][j] = m_data[i][j] - image.m_data[i][j];
		}
	}
	return result;
}

Image Image::operator*(double s) {
	for (int i = 0; i < m_width; ++i) {
		for (int j = 0; j < m_height; ++j) {
			m_data[i][j] = m_data[i][j] * s;
		}
	}
	return *this;
}

unsigned char* Image::row(int y) {
	if (y >= m_height || y < 0)
		throw std::exception();
	return m_data[y];
}

bool Image::getROI(Image& roiImg, Rectangle roiRect) {
	if (roiImg.getW() < roiRect.getX() + roiRect.getW()|| roiImg.getH() < roiRect.getY() + roiRect.getH()) {
		return false;
	}
	Image result(roiRect.getW(), roiRect.getH());
	for (int i = 0; i < roiRect.getH(); ++i) {
		for (int j = 0; j < roiRect.getW(); ++j) {
			result.m_data[i][j] = roiImg.m_data[roiRect.getY() + i][roiRect.getX() + j];
		}
	}
	roiImg = result;
	return true;
}
bool Image::getROI(Image& roiImg, unsigned int x, unsigned int y, unsigned int	width, unsigned int height) {
	if (roiImg.getW() < x + width || roiImg.getH() < y + height) {
		return false;
	}

	Image result;
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			result.m_data[i][j] = roiImg.m_data[y + i][x + j];
		}
	}
	result = roiImg;
	return true;
}

const unsigned char& Image::at(unsigned int x, unsigned int y) const{
	return m_data[x][y];
}