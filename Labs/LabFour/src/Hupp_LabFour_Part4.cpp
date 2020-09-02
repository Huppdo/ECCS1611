//Dominic Hupp - ECCS1611 - Lab Four Part Four
/*
	Make change. View documentation folder for more information
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main(void) {
	//Establish constants
	const double DOLLAR_VALUE = 1;
	const double QUARTER_VALUE = 0.25;
	const double DIME_VALUE = 0.10;
	const double NICKLE_VALUE = 0.05;
	const double PENNY_VALUE = 0.01;

	//Establish user input variables
	double payment_recieved = 0.00;
	double total_cost = 0;

	//Establish hidden variables
	double change_needed = 0;
	double remaining_change = 0;
	int dollars_change = 0;
	int quarters_change = 0;
	int dime_change = 0;
	int nickle_change = 0;
	int penny_change = 0;

	//Get user values
	cout << "Customer owes $";
	cin >> total_cost;
	cout << "Customer pays $";
	cin >> payment_recieved;

	//Get change needed
	change_needed = payment_recieved - total_cost;

	//Print out the changed needed
	cout << "Change due is $" << fixed << setprecision(2) << change_needed << endl;

	//Compute the change values to return (dollars, quarters, etc)
	//This uses the fact that double to int drops the floating point values
	remaining_change = change_needed;
	dollars_change = remaining_change / DOLLAR_VALUE; //Calculate dollars in change
	remaining_change -= dollars_change * DOLLAR_VALUE - 0.001; //Fix double precision being too high by subtracting a miniscule amnt
	quarters_change = remaining_change / QUARTER_VALUE; //Calculate quarters in change
	remaining_change -= quarters_change * QUARTER_VALUE - 0.001; //Fix double precision being too high by subtracting a miniscule amnt
	dime_change = remaining_change / DIME_VALUE; //Calculate dimes in change
	remaining_change -= dime_change * DIME_VALUE - 0.001; //Fix double precision being too high by subtracting a miniscule amnt
	nickle_change = remaining_change / NICKLE_VALUE; //Calculate nickles in change
	remaining_change -= nickle_change * NICKLE_VALUE - 0.001; //Fix double precision being too high by subtracting a miniscule amnt
	penny_change = remaining_change / PENNY_VALUE; //Calculate pennies in change
	remaining_change -= penny_change * PENNY_VALUE - 0.001; //Fix double precision being too high by subtracting a miniscule amnt

	//Verify that all change is accounted for
	if (remaining_change >= 0.01) {
		cout << "The change calculation failed!" << endl;
		return 1;
	}

	//Determine plural or singular
	if (dollars_change == 1) {
		cout << dollars_change << " dollar" << endl;
	}
	else if (dollars_change > 1) {
		cout << dollars_change << " dollars" << endl;
	}
	if (quarters_change == 1) {
		cout << quarters_change << " quarter" << endl;
	}
	else if (quarters_change > 1) {
		cout << quarters_change << " quarters" << endl;
	}
	if (dime_change == 1) {
		cout << dime_change << " dime" << endl;
	}
	else if (dime_change > 1) {
		cout << dime_change << " dimes" << endl;
	}
	if (nickle_change == 1) {
		cout << nickle_change << " nickle" << endl;
	}
	else if (nickle_change > 1) {
		cout << nickle_change << " nickles" << endl;
	}
	if (penny_change == 1) {
		cout << penny_change << " penny" << endl;
	}
	else if (penny_change > 1) {
		cout << penny_change << " pennies" << endl;
	}
}