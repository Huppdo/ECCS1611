//Dominic Hupp - ECCS1611 - Lab 5 - 9/8/20
/* 
	Use two for loops to complete two seperate calculations
*/

#include <iostream>
using namespace std;

int main(void) {
	//Setup variables
	int sumEvenNumbers = 0;
	int sumAllSquares = 0;

	for (int i = 2; i < 101; i++) {
		sumEvenNumbers += (i % 2 == 0) ? i : 0;
	}
	for (int i = 1; i < 101; i++) {
		sumAllSquares += (i * i);
	}

	cout << "The sum of all even numbers between 2 and 100, inclusive, is " << sumEvenNumbers << ".\n";
	cout << "The sum of all squares between 1 and 100, inclusive, is " << sumAllSquares << ".\n";
}