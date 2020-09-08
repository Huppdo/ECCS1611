//Dominic Hupp - ECCS1611 - Lab 5 - 9/8/20
/*
	Accept input until cin.fail()
*/

#include <iostream>
using namespace std;

int main(void) {
	int largest = -1;
	int smallest = 1000000;
	int evens = 0;
	int odds = 0;
	while (true) {
		int number;
		cout << "Enter number or Q to quit: ";
		cin >> number;
		if (cin.fail()) {
			break;
		}
		if (number > largest) {
			largest = number;
		}
		if (number < smallest) {
			smallest = number;
		}
		if (number % 2 == 0) {
			evens += 1;
		}
		else {
			odds += 1;
		}
	}
	cout << "Largest value: " << largest;
	cout << " Smallest value: " << smallest << endl;
	cout << "Even Number Count: " << evens;
	cout << " Odd Number Count: " << odds << endl << endl;
}