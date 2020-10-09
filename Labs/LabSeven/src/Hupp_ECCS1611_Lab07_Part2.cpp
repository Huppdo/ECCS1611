//Dominic Hupp - Lab 7 - 10/7/20

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

bool all_the_same(int x, int y, int z);
bool all_different(int x, int y, int z);
bool sorted(int x, int y, int z);

int main(void) {
	string userInput = "";

	while (userInput != "q") {
		int one = 0;
		int two = 0;
		int thr = 0;
		
		userInput == "";

		do {
			cout << "Enter 3 numbers (x y z) or q(uit): ";
			getline(cin, userInput);
		} while (userInput == "" || userInput == " ");

		if (userInput == "q" || userInput == "Q") {
			break;
		}
	
		istringstream strStream(userInput);
		strStream >> one >> two >> thr;

		//cout << one << two << thr << endl;

		if (all_the_same(one, two, thr)) {
			cout << "All the numbers were the same" << endl;
		}
		else {
			cout << "Not all the numbers were the same" << endl;
		}

		if (all_different(one, two, thr)) {
			cout << "All the numbers were different" << endl;
		}
		else {
			cout << "Not all the numbers were different" << endl;
		}

		if (sorted(one, two, thr)) {
			cout << "The numbers are in ascending order" << endl;
		}
		else {
			cout << "The numbers are not in ascending order" << endl;
		}
	}
}

bool all_the_same(int x, int y, int z) {
	if (x == y && y == z) {
		return true;
	}
	return false;
}

bool all_different(int x, int y, int z) {
	if (x != y && y != z && x != z) {
		return true;
	}
	return false;
}

bool sorted(int x, int y, int z) {
	if (x <= y and y <= z) {
		return true;
	}
	return false;
}