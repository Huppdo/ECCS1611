//Dominic Hupp - Lab 7 - 10/7/20

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int first_digit(int n);
int last_digit(int n);
int digits(int n);

int main(void) {
	string userInput = "";

	while (userInput != "q") {
		int num = 0;

		userInput == "";

		do {
			cout << "Enter 3 numbers (x y z) or q(uit): ";
			getline(cin, userInput);
		} while (userInput == "" || userInput == " ");

		if (userInput == "q" || userInput == "Q") {
			break;
		}

		num = stoi(userInput);

		cout << "The first digit is: " << (char)first_digit(num) << endl;
		cout << "The last digit is: " << (char)last_digit(num) << endl;
		cout << "The length is: " << digits(num) << endl;
	}
}

int first_digit(int n) {
	string nStr = to_string(n);
	return nStr.at(0);
}

int last_digit(int n) {
	string nStr = to_string(n);
	return nStr.at(nStr.length()-1);
}

int digits(int n) {
	string nStr = to_string(n);
	return nStr.length();
}