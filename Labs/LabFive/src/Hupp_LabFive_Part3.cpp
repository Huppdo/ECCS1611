//Dominic Hupp - ECCS1611 - Lab 5 Part 3 - 9/8/20
/*
	Convert from base 10 to base 2
*/

#include <iostream>
using namespace std;

int main(void) {
	//Setup vars
	int number = -1;

	//Get user input
	cout << "Please enter a number: ";
	cin >> number;

	while (number > 0) {
		cout << number % 2 << endl;
		number /= 2;
	}
}