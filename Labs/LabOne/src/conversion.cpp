/// conversion.cpp - Dominic Hupp - August 12th, 2020
// Program will accept input in the form: number letter (e.g. 32 F)
// and will convert the specified temperature from Fahrenheit to Celsius,
// or vice versa, depending on input (either C or F).

#include <iostream>      // import library that allows us to use cin and cout

using namespace std;

const char FAHRENHEIT = 'F';
const char CELSIUS = 'C';

int main(void) {
    cout.setf(ios::fixed); //Displays the number w/o any extra zeros
    cout.setf(ios::showpoint); //Displays zeros for floating point representations, even for whole numbers
    cout.precision(1); //Displays to one place after the decimal

    // variable declarations
    double inputTemperature; //Numerical representation of the input
    double convertedTemperature; //Input value converted to the new scale
    char   temperatureScale; //Character representation of the scale identifier input (C or F)
    char   convertedScale; //Character representation of the scale identifier after conversion (C or F)

    // get the temperature to be converted
	/*
	 * Since one of our inputs is a lowercase, that means we need to convert the provided input
	 * into all uppercase or all lowercase. Because the program already uses uppercase char values as the
	 * constants for temperature, I figured it would be more effective to use.
	 *
	 * I accomplished the conversion by using the toupper function built into C++ and then casting it to
	 * a char, since toupper returns an int. Casting in C++ is an operator built in to forcefully convert
	 * from one data type into another.
	 */
    cout << "Please enter temperature - indicate scale with C or F: ";
    cin >> inputTemperature >> temperatureScale;

	/*
	 *Here's where I converted temperatureScale to an int using toupper and then cast it back to a char.
	 */
    temperatureScale = char(toupper(temperatureScale));
	

    // determine if legal scale was entered
    if (temperatureScale != FAHRENHEIT && temperatureScale != CELSIUS) {
        // bailing out of program due to illegal input
        cout << "Sorry - temperature scale must be either C or F.\n";
        cout << "Press 'Enter' to continue...";
        cin.ignore();
        cin.get();
        return 1;
    }

    // determine what conversion formula to use
    if (temperatureScale == FAHRENHEIT) {
        //I added parentheses here in the formula to ensure order of operations was being followed.
        convertedTemperature = 5.0 / 9.0 * (inputTemperature - 32.0); 
        convertedScale = CELSIUS;
    }
    else {// input was in Celsius
    	//I also added parentheses here, even though order of operations was already being followed successfully.
        convertedTemperature = ((9.0 / 5.0) * inputTemperature) + 32.0;
        convertedScale = FAHRENHEIT;
    }

    // present result and terminate program execution
    cout << convertedTemperature << " " << convertedScale << endl;
    cout << "Press 'Enter' to continue...";
    cin.ignore();
    cin.get();
    return 0;
}
