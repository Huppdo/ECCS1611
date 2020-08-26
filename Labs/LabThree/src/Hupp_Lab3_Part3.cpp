//Dominic Hupp - ECCS1611 - Lab 3 Part 3 - 8/26/20
/*
	Determine the price of a bookstore order from the total price and the number of books ordered
*/

#include <iostream>
using namespace std;

int main() {
	//Establish user input variables
	double priceOfBooks = 0;
	int numberOfBooks = 0;

	//Establish constants
	const double taxRate = 1.075; //7.5%
	const double shippingCharge = 2.50; //Per book

	//Establish hidden variables
	double totalPrice = 0;

	//Get user input
	cout << "Enter total cost of all books: $";
	cin >> priceOfBooks;
	cout << "Enter total number of books purchased: ";
	cin >> numberOfBooks;

	//Compute total cost
	totalPrice = priceOfBooks * taxRate;
	totalPrice += numberOfBooks * shippingCharge;

	//Output total price
	cout << endl << "Price of order is $" << totalPrice << endl << endl;
}