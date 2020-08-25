//Dominic Hupp - ECCS1611 - Prelab 02 (Prelab 3)

#include <iostream>
using namespace std;

int main() {
	cout.setf(ios::fixed); //Displays the number w/o any extra zeros
	cout.setf(ios::showpoint); //Displays zeros for floating point representations, even for whole numbers
	cout.precision(2); //Displays to one place after the decimal

	int fenceLength = 0; //will always be a multiple of 15!
	
	//constants
	const int LENGTH_PER_RAIL = 15, RAILS_PER_SECTION = 4;
	const double COST_PER_POST = 16.00, COST_PER_RAIL = 20.00;

	//needs computed
	int rails = 0, posts = 0;
	double finalCost = 0;

	//get fence length
	cout << "Please input your desired fence length (as a multiple of 15):  ";
	cin >> fenceLength;

	//calculate number of rails and posts
	rails = (fenceLength / LENGTH_PER_RAIL) + 1;
	posts = (rails - 1) * RAILS_PER_SECTION;

	//calculate final cost
	finalCost = (rails * COST_PER_RAIL) + (posts * COST_PER_POST);

	//print final cost
	cout << "The final cost of the fence will be $" << finalCost << endl << endl;
}
