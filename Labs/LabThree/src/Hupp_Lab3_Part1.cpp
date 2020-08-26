//Dominic Hupp - ECCS1611 - Lab Three Part One - 8/26/20
/*
	Accept two numbers from the using and then print the sum, difference, product, and average.
*/

#include <iostream>
using namespace std;

int main() {
	//Establish user input variables
	int integerOne = 0;
	int integerTwo = 0;

	//Establish temporary variables
	double average = 0;
	
	//Get user input
	cout << "Enter integer 1: ";
	cin >> integerOne;
	cout << "Enter integer 2: ";
	cin >> integerTwo;

	//Print out Sum
	cout << "Sum is " << integerOne + integerTwo << endl;

	//Print out Difference
	cout << "Difference is " << integerOne - integerTwo << endl;

	//Print out Product
	cout << "Product is " << integerOne * integerTwo << endl;

	//Print out Average
	average = integerOne + integerTwo;
	average = average / 2;
	cout << "Average is " << average << endl;
}