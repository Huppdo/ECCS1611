//Dominic Hupp - Lab 7 - 10/7/20

#include <iostream>
using namespace std;

double smallest(double x, double y, double z);
double average(double x, double y, double z);

int main(void) {
	double one = 0;
	double two = 0;
	double thr = 0;

	cout << "Enter three numbers: ";
	cin >> one >> two >> thr;

	cout << endl << "Smallest of the three numbers: " << smallest(one, two, thr) << endl;
	cout << "Average of the three numbers: " << average(one, two, thr) << endl;
}

double smallest(double x, double y, double z) {
	if (x < y && x < z) {
		return x;
	}
	else if (y < x and y < z) {
		return y;
	}
	else {
		return z;
	}
}

double average(double x, double y, double z) {
	return (x + y + z) / 3;
}