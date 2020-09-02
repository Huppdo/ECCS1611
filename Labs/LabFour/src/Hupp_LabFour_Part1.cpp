//Dominic Hupp - ECCS1611 - Lab Four Part One
/*
	Reads an integer temperature value and the letter C for Celsius or F for Fahrenheit. 
	Prints whether water is liquid, solid, or gaseous at the given temperature at sea level.
*/

#include <string>
#include <iostream>
using namespace std;

int main(void) {
	//Establish user input variables
	int temp = -1;
	char units = '0';

	//Establish constant variables
	const int FREEZING_POINT_F = 32;
	const int FREEZING_POINT_C = 0;
	const int BOILING_POINT_F = 212;
	const int BOILING_POINT_C = 100;

	//Get user input
	cout << "Please enter temperature value: ";
	cin >> temp >> units;

	/*
	 *Here's where I converted temperatureScale to an int using toupper and then cast it back to a char.
	 */
	units = char(toupper(units));

	if (units != 'C' && units != 'F') {
		cout << endl << "Invalid unit, aborting program" << endl;
		return 1;
	}

	if (units == 'C') {
		if (temp < FREEZING_POINT_C) {
			cout << "Water is a solid at that temperature." << endl;
		}
		else if (temp == FREEZING_POINT_C) {
			cout << "Water is both a solid and a liquid at that temperature." << endl;
		}
		else if (temp < BOILING_POINT_C) {
			cout << "Water is a liquid at that temperature." << endl;
		}
		else if (temp == BOILING_POINT_C) {
			cout << "Water is both a liquid and a gas at that temperature." << endl;
		}
		else {
			cout << "Water is a gas at that temperature." << endl;
		}
	}
	else if (units == 'F') {
		if (temp < FREEZING_POINT_F) {
			cout << "Water is a solid at that temperature." << endl;
		}
		else if (temp == FREEZING_POINT_F) {
			cout << "Water is both a solid and a liquid at that temperature." << endl;
		}
		else if (temp < BOILING_POINT_F) {
			cout << "Water is a liquid at that temperature." << endl;
		}
		else if (temp == BOILING_POINT_F) {
			cout << "Water is both a liquid and a gas at that temperature." << endl;
		}
		else {
			cout << "Water is a gas at that temperature." << endl;
		}
	}
}