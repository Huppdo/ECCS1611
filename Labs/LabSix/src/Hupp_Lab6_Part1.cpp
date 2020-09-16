//Dominic Hupp - ECCS1611 - 9/16/20 - Lab 6 Part 1
/*
	Displays, using asterisks, a ﬁlled diamond of the given side length
*/

#include <iostream>
using namespace std;

int main(void) {
	//Setup variables
	int sideLength = 0;
	char printChar = '*';
	char blankChar = ' ';

	//Get user input
	cout << "Enter number of asterisks per side: ";
	cin >> sideLength;

	//Print out top of diamond
	for (int i = 0; i < (sideLength); i++) {
		for (int j = 0; j < (sideLength -(i% sideLength)); j++) {
			cout << blankChar;
		}
		for (int j = 0; j < ((2 * (i % sideLength)) + 1); j++) {
			cout << printChar;
		}
		for (int j = 0; j < (sideLength - (i % sideLength)); j++) {
			cout << blankChar;
		}
		cout << endl;
	}

	//Print out bottom of diamond
	for (int i = (sideLength-2); i >= 0; i--) {
		for (int j = 0; j < (sideLength - (i % sideLength)); j++) {
			cout << blankChar;
		}
		for (int j = 0; j < ((2 * (i % sideLength)) + 1); j++) {
			cout << printChar;
		}
		for (int j = 0; j < (sideLength - (i % sideLength)); j++) {
			cout << blankChar;
		}
		cout << endl;
	}
}