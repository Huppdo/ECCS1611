//Dominic Hupp - ECCS1611 - Prelab05 - 9/15/20

#include <iostream>
#include <iomanip>
using namespace std;


int main(void) {
	int iterations = 100000;
	double pi = 4;

	for (double i = 0; i < iterations; i++) {
		double value = (4.0 / ((2 * i) - 1));
		if ((int)i % 2 == 1) {
			value *= -1;
		}
		pi += value;
	}

	cout << fixed << setprecision(13) << pi*-1;
}
