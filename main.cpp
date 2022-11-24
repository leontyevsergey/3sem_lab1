#include <iostream>
#include "Binary.h"
using namespace std;

void Set_size(int* x, int* y) {
	do {
		std::cout << "Input width: ";
		std::cin >> *x;
	} while (*x <= 0);
	do {
		std::cout << "Input height: ";
		std::cin >> *y;
	} while (*y <= 0);
}

Binary_Image Create_Image() {
	int x = 0, y = 0, value;
	bool b;
	Set_size(&x, &y);
	Binary_Image tmp(x, y);
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) {
			do {
				cout << "Input pixel[" << i << "][" << j << "]: ";
				cin >> value;
			} while (value != 1 && value != 0);
			if (value == 1)
				b = true;
			else
				b = false;
			tmp(i, j) = b;
		}
	}
	return tmp;
}

Binary_Image Create_Circle() {
	std::cout << "Create binary image" << endl;
	int x, y, radius = 0;
	cout << "Enter size of image: " << endl;
	Set_size(&x, &y);
	Binary_Image tmp(x, y);
	cout << "Enter center of circle:";
	do {
		cout << "\nx =  ";
		cin >> x;
	} while (x - 1 >= tmp.Get_x());
	do {
		cout << "\ny =  ";
		cin >> y;
	} while (y - 1 >= tmp.Get_y());
	do {
		cout << endl << "Enter radius of circle: ";
		cin >> radius;
	} while (radius > tmp.Get_x() && radius > tmp.Get_y());
	x--;
	y--;
	for (int i = 0; i < tmp.Get_x(); i++) {
		for (int j = 0; j < tmp.Get_y(); j++) {
			tmp(i, j) = false;
		}
	}
	for (int i = 0; i < tmp.Get_x(); i++) {
		for (int j = 0; j < tmp.Get_y(); j++) {
			if (((i + radius == x) || (i - radius == x)) && ((j > y - radius) && (j < y + radius)))
				tmp(i, j) = true;
		}
	}
	for (int i = 0; i < tmp.Get_y(); i++) {
		for (int j = 0; j < tmp.Get_x(); j++) {
			if (((i + radius == y) || (i - radius == y)) && ((j > x - radius) && (j < x + radius)))
				tmp(j, i) = true;
		}
	}
	return tmp;
}

int main()
{
	bool b = true;
	/*Binary_Image BI3(Create_Image());
	cout << BI3 << "\n";
	Binary_Image BI4 = BI3;
	cout << BI4 << endl;
	BI4 = BI4 + b;
	cout << BI4 << endl;
	std::cout << BI3 * BI4 << endl;
	if (BI4 == BI3)
		std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
	cout << endl;*/
	cout << "Create first image\n";
	Binary_Image BI1(Create_Image());
	cout << "Create second image\n";
	Binary_Image BI2(Create_Image());
	cout << BI1 << endl;
	cout << !BI1 << endl;
	cout << BI2 << endl;
	cout << BI1 + BI2 << endl;
	cout << BI1 * BI2 << endl;
	cout << "Input b: ";
	cin >> b;
	cout << BI1 + b << endl;
	cout << BI2 * b << endl;
	std::cout << BI2(1, 1) << endl;
	BI2(1, 1) = !BI2(1, 1);
	std::cout << BI2(1, 1) << endl;
	cout << BI1.Ratio() << endl;
	cout << BI1.Get_x() << "\t" << BI1.Get_y() << "\n";
	Binary_Image BIC(Create_Circle());
	cout << BIC;
}