//Dominic Hupp - ECCS1611 - Lab 3 Part 2 - 8/26/20
/*
	Determine the cost of owning a car with the provided inputs
*/

#include <iostream>
using namespace std;

int main() {
	//Establish user input variables
	int costOfCar = 0; 
	double milesPerGallon = 0;
	int milesPerYear = 0;
	double gasPrice = 0;
	double yearsOfUse = 0;
	int resaleAmnt = 0;

	//Establish temporary/behind the scenes variables
	double netCost = 0;

	//Get user input data
	cout << "Enter cost of car: $";
	cin >> costOfCar;
	cout << "Enter MPG: ";
	cin >> milesPerGallon;
	cout << "Enter miles driven per year: ";
	cin >> milesPerYear;
	cout << "Enter gas price: $";
	cin >> gasPrice;
	cout << "Enter years of use: ";
	cin >> yearsOfUse;
	cout << "Enter car resale amount: $";
	cin >> resaleAmnt;

	//Calculate net cost
	netCost = costOfCar; //Start by using the initial price of the car
	netCost += (milesPerYear / milesPerGallon * gasPrice * yearsOfUse); //Get the total cost in gas spent
	netCost -= resaleAmnt;

	//Print out net cost
	cout << endl << "Net cost of car ownership: $" << netCost << endl << endl;
}