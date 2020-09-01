//Dominic Hupp - ECCS1611 - Prelab 3
/*
	Compute tax rate and total cost
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
	//Initialize user input variables
	double taxRate = 0, totalCost = 0;

	//Initialize hidden variables
	double taxOnPurchase = 0;
	int roundingPlace = -1;

	//Get user input
	cout << "Please enter the tax rate without the percentage sign (ex. 6.5) -- ";
	cin >> taxRate;
	cout << endl << "Please enter the total cost of your purchase (ex. 15.01) -- ";
	cin >> totalCost;

	//Change tax rate to decimal from percent
	taxRate /= 100;

	//Compute tax on purchase
	taxOnPurchase = taxRate * totalCost;

	//Compute third decimal place
	roundingPlace = (int)(taxOnPurchase * 1000) % 10;

	//Decide if to round or not
	if (roundingPlace < 0) {
		cout << "Error in code; aborting" << endl << endl;
		return 1;
	}
	else if (roundingPlace <= 4) {
		cout << "3rd Decimal smaller than 4, rounding down" << endl << endl;
		taxOnPurchase += 0.00; //Does nothing
	}
	else {
		cout << "3rd Decimal larger than 4, rounding up" << endl << endl;
		taxOnPurchase += 0.01;
	}

	//Ensure rounded value only has two decimal places
	taxOnPurchase = (double)((int)(taxOnPurchase * 100))/100;
	
	//Add tax to total cost
	totalCost = totalCost + taxOnPurchase;

	//Display total cost
	cout << "The total is $" << fixed << setprecision(2) << taxOnPurchase << endl << endl;
	cout << "The total cost with tax is $" << fixed << setprecision(2) << totalCost;
	cout << endl << endl;
}