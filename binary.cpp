#include "Binary.h"
#include <iostream>
using namespace std;

Binary_Image::Binary_Image() {
	x = 0;
	y = 0;
	image = NULL;
}

Binary_Image::Binary_Image(const int coor_x, const int coor_y) {
	if (coor_x <= 0 || coor_y <= 0) {
		throw "The number of rows and columns should be >0";
	}
	x = coor_x;
	y = coor_y;
	image = new bool* [x];
	for (int i = 0; i < x; ++i) {
		image[i] = new bool[y];
	}
}

Binary_Image::Binary_Image(const Binary_Image& copy)
{
	x = copy.x;
	y = copy.y;
	image = new bool* [x];
	for (int i = 0; i < x; i++)
	{
		image[i] = new bool[y];
		for (int j = 0; j < y; j++)
		{
			image[i][j] = copy.image[i][j];
		}
	}
}


bool& Binary_Image::operator()(const int coor_x, const int coor_y) {
	if (coor_x > x || coor_y > y || coor_x < 0 || coor_y < 0)
		throw "Incorrect coordinates";
	return image[coor_x][coor_y];
}

const bool& Binary_Image::operator()(const int coor_x, const int coor_y) const {
	if (coor_x > x || coor_y > y || coor_x < 0 || coor_y < 0)
		throw "Incorrect coordinates";
	return image[coor_x][coor_y];
}

Binary_Image Binary_Image::operator*(const Binary_Image& a_image) const {
	int x_min = 0, y_min = 0, result_x, result_y;
	if (x > a_image.x) {
		result_x = x;
		x_min = a_image.x;
	}
	else
	{
		result_x = a_image.x;
		x_min = x;
	}
	if (y > a_image.y) {
		result_y = y;
		y_min = a_image.y;
	}
	else
	{
		result_y = a_image.y;
		y_min = y;
	}
	Binary_Image result_image(result_x, result_y);
	for (int i = 0; i < x_min; ++i) {
		for (int j = 0; j < y_min; ++j) {
			if (image[i][j] && a_image.image[i][j])
				result_image.image[i][j] = true;
			else
				result_image.image[i][j] = false;
		}
	}
	if (x > a_image.x || x < a_image.x) {
		for (int i = x_min; i < result_x; ++i) {
			for (int j = 0; j < result_y; ++j) {
				result_image.image[i][j] = image[i][j];
			}
		}
	}
	if (y > a_image.y || y < a_image.y) {
		for (int i = 0; i < x_min; ++i) {
			for (int j = y_min; j < result_y; ++j) {
				result_image.image[i][j] = image[i][j];
			}
		}
	}
	return result_image;
}

Binary_Image Binary_Image::operator+(const Binary_Image& a_image) const {
	int x_min = 0, y_min = 0, result_x, result_y;
	if (x > a_image.x) {
		result_x = x;
		x_min = a_image.x;
	}
	else
	{
		result_x = a_image.x;
		x_min = x;
	}
	if (y > a_image.y) {
		result_y = y;
		y_min = a_image.y;
	}
	else
	{
		result_y = a_image.y;
		y_min = y;
	}
	Binary_Image result_image(result_x, result_y);
	for (int i = 0; i < x_min; ++i) {
		for (int j = 0; j < y_min; ++j) {
			if (image[i][j] || a_image.image[i][j])
				result_image.image[i][j] = true;
			else
				result_image.image[i][j] = false;
		}
	}
	if (x > a_image.x || x < a_image.x) {
		for (int i = x_min; i < result_x; ++i) {
			for (int j = 0; j < result_y; ++j) {
				result_image.image[i][j] = image[i][j];
			}
		}
	}
	if (y > a_image.y || y < a_image.y) {
		for (int i = 0; i < x_min; ++i) {
			for (int j = y_min; j < result_y; ++j) {
				result_image.image[i][j] = image[i][j];
			}
		}
	}

	return result_image;
}

Binary_Image Binary_Image::operator*(const bool a_b) {
	Binary_Image result_image(x, y);
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) {
			result_image.image[i][j] = image[i][j] && a_b;
		}
	}
	return result_image;
}

Binary_Image Binary_Image::operator+(const bool a_b) {
	Binary_Image result_image(x, y);
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) {
			result_image.image[i][j] = image[i][j] || a_b;
		}
	}
	return result_image;
}

Binary_Image Binary_Image::operator!() {
	Binary_Image result_image(x, y);
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) {
			result_image.image[i][j] = !image[i][j];
		}
	}
	return result_image;
}

double Binary_Image::Ratio() {
	double temp = 0, d_x = x, d_y = y;
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) {
			if (image[i][j])
				temp++;
		}
	}
	return(temp / (d_x * d_y));
}

ostream& operator <<(ostream& os, const Binary_Image& a_image) {
	for (int i = 0; i < a_image.x; ++i) {
		for (int j = 0; j < a_image.y; ++j) {
			if (a_image.image[i][j])
				os << "\t1";
			else
				os << "\t.";
		}
		os << endl;
	}
	return os;
}

int Binary_Image::Get_x() const {
	return x;
}

int Binary_Image::Get_y() const {
	return y;
}

Binary_Image Binary_Image::operator=(const Binary_Image& a_image) {
	x = a_image.x;
	y = a_image.y;
	Binary_Image result(x, y);
	if (x != a_image.x || y != a_image.y) {
		if (image) {
			for (int i = 0; i < x; ++i) {
				delete[] image[i];
			}
		}
		delete[] image;
		image = new bool* [x];
		for (int i = 0; i < x; ++i) {
			image[i] = new bool[y];
		}
	}

	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) {
			image[i][j] = a_image.image[i][j];
			a_image.image[i][j] = image[i][j];
		}
	}
	return a_image;
}

bool Binary_Image::operator==(const Binary_Image& a_image) const {
	if (x == a_image.x && y == a_image.y) {
		for (int i = 0; i < x; ++i) {
			for (int j = 0; j < y; ++j) {
				if (image[i][j] == a_image.image[i][j])
					continue;
				else
				{
					return false;
				}
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

Binary_Image::~Binary_Image() {
	if (image) {
		for (int i = 0; i < x; ++i) {
			delete[] image[i];
		}
	}
	delete[] image;
}