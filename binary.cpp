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


bool& Binary_Image::operator()(const int coor_x, const int coor_y, const bool b) {
	if (coor_x > x || coor_y > y || coor_x < 0 || coor_y < 0)
		throw "Incorrect coordinates";
	image[coor_x][coor_y] = b;
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