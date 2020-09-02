//Dominic Hupp - ECCS1611 - Lab Four Part Three
/*
	Reads an integer and prints how many digits the number has, by checking whether the number is >=10, >=100, and so on. 
	Assume that the absolute value of any entered integer is less than two billion. 
*/

#include <string>
#include <iostream>
using namespace std;

int main(void) {
	//Establish user input variable
	int userInput = -1;

	//Get user input
	cout << "Please enter an integer: ";
	cin >> userInput;

	//Checks if less than 0
	if (userInput < 0) {
		userInput *= -1;
	}

	//Change to string
	string userInputStr = to_string(userInput);

	//Output length
	cout << "The number has " << userInputStr.length() << " digits.";
}