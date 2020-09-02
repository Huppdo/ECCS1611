//Dominic Hupp -- ECCS1611 - Lab Four Part Two
/*
	Reads in three floating-point numbers and prints the largest of the three inputs. 
*/

#include <iostream>
using namespace std;

int main(void) {
	//Establish user input variables
	double doubleOne = -1;
	double doubleTwo = -1;
	double doubleThree = -1;

	//Get user inputs
	cout << "Please enter three numbers: ";
	cin >> doubleOne >> doubleTwo >> doubleThree;

	//Compare!
	if (doubleOne >= doubleTwo && doubleOne >= doubleThree) {
		cout << "The largest number is " << doubleOne << "." << endl;
	}
	else if (doubleTwo >= doubleThree) {
		cout << "The largest number is " << doubleTwo << "." << endl;
	}
	else {
		cout << "The largest number is " << doubleThree << "." << endl;
	}
}