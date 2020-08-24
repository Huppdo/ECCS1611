//Dominic Hupp - ECCS1611 - Prelab 02 (Prelab 3)

#include <iostream>
using namespace std;

int main() {
	cout.setf(ios::fixed); //Displays the number w/o any extra zeros
	cout.setf(ios::showpoint); //Displays zeros for floating point representations, even for whole numbers
	cout.precision(2); //Displays to one place after the decimal

	int fenceLength = 0; //will always be a multiple of 10!
	
	//constants
	const int LENGTH_PER_RAIL = 10;
	const int RAILS_PER_SECTION = 3;
	const double COST_PER_POST = 10.98;
	const double COST_PER_RAIL = 9.97;

	//needs computed
	int sections = 0;
	int rails = 0;
	int posts = 0;
	double finalCost = 0;

	//get fence length
	cout << "Please input your desired fence length (as a multiple of 10):  ";
	cin >> fenceLength;
	
	//calculate number of sections based on rail length
	sections = fenceLength / LENGTH_PER_RAIL;

	//calculate number of rails and posts
	rails = sections * RAILS_PER_SECTION;
	posts = sections + 1;

	//calculate final cost
	finalCost = (rails * COST_PER_RAIL) + (posts * COST_PER_POST);

	//print final cost
	cout << "The final cost of the fence will be $" << finalCost << endl << endl;
}