//Dominic Hupp - ECCS1611 - Prelab05 - 9/15/20

#include <iostream>
using namespace std;

void printTop(int endLength);

char printChar = '*';
char blankChar = ' ';

int main(void) {
	//Setup variables
	int lengthOfSquare = -1;

	//Get user input
	cout << "Enter the length of the square sides: ";
	cin >> lengthOfSquare;
	cout << endl;

	//Print out squares
	printTop(lengthOfSquare);
	for (int i = 0; i < lengthOfSquare - 2; i++) {
		for (int j = 0; j < ((lengthOfSquare * 2) + 1); j++) {
			if (j < lengthOfSquare) {
				cout << printChar;
			}
			else if (j == lengthOfSquare) {
				cout << blankChar;
			}
			else if (j == lengthOfSquare + 1) {
				cout << printChar;
			}
			else if (j == (lengthOfSquare * 2)) {
				cout << printChar;
			}
			else {
				cout << blankChar;
			}
		}
		cout << endl;
	}
	printTop(lengthOfSquare);

}

void printTop(int endLength) {
	for (int a = 0; a < endLength; a++) {
		cout << printChar;
	}
	cout << blankChar;
	for (int a = 0; a < endLength; a++) {
		cout << printChar;
	}
	cout << endl;
}