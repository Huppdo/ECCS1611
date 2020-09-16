//Dominic Hupp - ECCS1611 - Lab 6 Part 2 - 9/16/20
/*
	Reads a set of floating-point data values that uses an appropriate sentinel for indicating the end of the data set. 
	When all values have been read, prints out the count of the values, the average, and the standard deviation
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
	//Setup variables
	double avg = 0;
	int count = 0;
	double stanDev = -1;
	double sumOfSquares = 0;
	double temp = 0;

	//Start getting user input
	cin.clear();
	cout << "Enter numbers - Q to quit: ";
	while (true) {
		cin >> temp;
		if (cin.fail()) {
			break;
		}
		//cout << temp << endl;
		avg += temp;
		count++;
		sumOfSquares += (temp * temp);
	}
	if (count == 0) {
		cout << "No data to process - exiting..." << endl;
	} else {
		stanDev = (sumOfSquares - ((avg * avg)/count));
		stanDev = stanDev / (count - 1);
		stanDev = sqrt(stanDev);
		avg = avg / count;
		cout << "n = " << count << ", average = " << avg << ", standard deviation = " << stanDev << endl;
	} 
	cout << "Press any key to continue..." << endl;
}