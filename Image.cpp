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
	this->m_height = other.getH();//schimb getH() etc
	this->m_width = other.getW();
	m_data = new unsigned char* [other.getH()];
	for (int i = 0; i < other.getH(); ++i) {
		m_data[i] = new unsigned char[other.getW()];
	}
	for (int i = 0; i < other.getH(); ++i) {
		for (int j = 0; j < other.getW(); ++j) {
			this->m_data[i][j] = other.m_data[i][j];
		}
	}
}

Image::~Image() {
	release();
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
			os << dt.m_data[i][j] << ' ';
		}
		os << '\n';
	}
	return os;
}

std::istream& operator>>(std::istream& is, Image& dt) {
	char text[1000];
	is.getline(text, 1000);
	if (strcmp(text, "P2")) {
		std::cout << "Error";
		return is;
	}
}