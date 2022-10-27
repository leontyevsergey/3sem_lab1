#pragma once
#include <iostream>
using namespace std;
class Binary_Image {
private:
	bool** image;
	int x, y;
public:
	Binary_Image();
	Binary_Image(const int x, const int y); //width, height
	Binary_Image(const Binary_Image& copy);
	bool& operator()(const int coor_x, const int coor_y, const bool b); //write
	const bool& operator()(const int coor_x, const int coor_y) const; //read
	Binary_Image operator =(const Binary_Image& a_image);
	Binary_Image operator *(const Binary_Image& a_image) const;
	Binary_Image operator +(const Binary_Image& a_image) const;