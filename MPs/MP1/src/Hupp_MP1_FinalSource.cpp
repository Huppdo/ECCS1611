//Dominic Hupp - ECCS1611 - MP1 - 8/27/20
/*
	This program allows for the fictional Jim’s Donut Shop in Vandalia to compute the amount that the customer owes
	to the store and how much money the store needs to return in change.
*/

#include <iostream> //Allows cout and cin
#include <math.h> //Allows for me to round
#include <stdlib.h> //Allows for me to use abs
#include <iomanip> //Allows for precision adjustment on cout
using namespace std;

int main() {
	//initialize constant variables
	const int DONUTS_PER_DOZEN = 12;
	const double COST_PER_SINGLE_REGULAR = 0.75;
	const double COST_PER_DOZEN_REGULAR = 7.99;
	const double COST_PER_SINGLE_FANCY = 0.85;
	const double COST_PER_DOZEN_FANCY = 8.49;
	const double TAX_RATE = 1.075; //7.5%
	const double DOLLAR_VALUE = 1;
	const double QUARTER_VALUE = 0.25;
	const double DIME_VALUE = 0.10;
	const double NICKLE_VALUE = 0.05;
	const double PENNY_VALUE = 0.01;
	const double COMPARISON_ACCURACY = 0.01;

	//initialize user input variables
	int regular_donuts_ordered = 0;
	int fancy_donuts_ordered = 0;
	double payment_recieved = 0.00;

	//initialize temporary variables
	int regular_dozens = 0;
	int regular_singles = 0;
	int fancy_dozens = 0;
	int fancy_singles = 0;
	double total_cost = 0;
	double change_needed = 0;
	double remaining_change = 0;
	int dollars_change = 0;
	int quarters_change = 0;
	int dime_change = 0;
	int nickle_change = 0;
	int penny_change = 0;

	//Get user input for donuts ordered
	cout << "Number of regular donuts ordered: ";
	cin >> regular_donuts_ordered;
	cout << "Number of fancy donuts ordered: ";
	cin >> fancy_donuts_ordered;

	//Compute singles and dozens
	regular_singles = regular_donuts_ordered % DONUTS_PER_DOZEN;
	regular_dozens = (regular_donuts_ordered - regular_singles) / DONUTS_PER_DOZEN;
	fancy_singles = fancy_donuts_ordered % DONUTS_PER_DOZEN;
	fancy_dozens = (fancy_donuts_ordered - fancy_singles) / DONUTS_PER_DOZEN;

	//Compute total cost for donuts
	total_cost = (regular_singles * COST_PER_SINGLE_REGULAR);
	total_cost += (regular_dozens * COST_PER_DOZEN_REGULAR);
	total_cost += (fancy_singles * COST_PER_SINGLE_FANCY);
	total_cost += (fancy_dozens * COST_PER_DOZEN_FANCY);

	//Add tax to total cost for donuts
	total_cost = total_cost * TAX_RATE;
	
	//Round the total cost to two decimal points
	total_cost = roundf(total_cost * 100) / 100;

	//Print out the cost of the donuts
	cout << "Customer owes $" << total_cost << endl;

	//Get user input for payment
	cout << "Customer pays $";
	cin >> payment_recieved;

	//Determine if exact change was provided
	if (abs(payment_recieved - total_cost) < COMPARISON_ACCURACY) {
		cout << "Exact payment received - no change owed.";
		return 0;
	}
	else if (payment_recieved < total_cost) {
		cout << "The customer did not pay enough money";
		return 0;
	}

	//If payment isn't exact, the program will continue to this point
	//Compute amount of change needed
	change_needed = payment_recieved - total_cost;

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
		cout << "Changed owed is $" << change_needed << endl;
		return 1;
	}

	//Print out the total amount 
	cout << "Changed owed is $" << fixed << setprecision(2) << change_needed << " - ";
	
	//Determine plural or singular
	if (dollars_change == 1) {
		cout << dollars_change << " dollar, ";
	}
	else if (dollars_change > 1) {
		cout << dollars_change << " dollars, ";
	}
	if (quarters_change == 1) {
		cout << quarters_change << " quarter, ";
	}
	else if (quarters_change > 1) {
		cout << quarters_change << " quarters, ";
	}
	if (dime_change == 1) {
		cout << dime_change << " dime, ";
	}
	else if (dime_change > 1) {
		cout << dime_change << " dimes, ";
	}
	if (nickle_change == 1) {
		cout << nickle_change << " nickle, ";
	}
	else if (nickle_change > 1) {
		cout << nickle_change << " nickles,";
	}
	if (penny_change == 1) {
		cout << penny_change << " penny, ";
	}
	else if (penny_change > 1) {
		cout << penny_change << " pennies, ";
	}

	//Remove final period and space and replace with period
	cout << "\b" << "\b" << "." << endl << endl;

	return 0;
}