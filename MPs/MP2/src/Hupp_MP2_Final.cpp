//Dominic Hupp - ECCS1611 - MP2 - 9/22/20
/*
	Plays the roll the dice game provided with the predetermined rules.
	Turns iterate between two people.
*/

#include <iostream>
#include <string>
using namespace std;

int  rollDie(void);
bool isTurnScoreLost(int die1value, int die2value);
bool isGameScoreLost(int die1value, int die2value);
char getUserInput(void);

int main(void) {
	//Establish variables
	bool playerOneTurn = true;
	int firstDie = 0;
	int secondDie = 0;
	int p1Score[2] = { 0,0 }; //Array[0] is total score, array[1] is turn score
	int p2Score[2] = { 0,0 }; //Array[0] is total score, array[1] is turn score

	//Play the game until one player has a score 100 or greater
	while (p1Score[0] < 100 && p2Score[0] < 100) {
		//Gets the values for both dies
		firstDie = rollDie();
		secondDie = rollDie();
		
		//Output die rolls
		cout << "Die #1 - " << firstDie << ", Die #2 - " << secondDie << endl;

		//Set the turn value to the scores combined
		if (playerOneTurn) {
			p1Score[1] += firstDie + secondDie;
		}
		else {
			p2Score[1] += firstDie + secondDie;
		}

		//Checks to see if either of the die rolls are 1s and sets turn score correctly
		if (isTurnScoreLost(firstDie, secondDie)) {
			if (playerOneTurn) {
				p1Score[1] = 0;
			}
			else {
				p2Score[1] = 0;
			}
		}

		//Checks to see if both die rolls are 1s and set the players score to 0
		//NOTE: This will always be true if the turn score is also lost.
		if (isGameScoreLost(firstDie, secondDie)) {
			if (playerOneTurn) {
				p1Score[0] = 0;
			}
			else {
				p2Score[0] = 0;
			}
		}

		//Evaluates whether the turn changes
		if (playerOneTurn) {
			//Print out the players current score
			cout << "Your Total Score: " << p1Score[0] << ", Your Turn Score: " << p1Score[1] << endl;

			//If the user says stop or lost their points
			if (p1Score[1] == 0 || getUserInput() == 's') {
				//Flip turns
				playerOneTurn = !playerOneTurn;
				p1Score[0] = p1Score[0] + p1Score[1];
				p1Score[1] = 0;
				cout << "Your Total Score: " << p1Score[0] << endl;
				cout << "-----" << endl;
			}
		}
		else {
			//Print out the computers current score
			cout << "Computer's Total Score: " << p2Score[0] << ", Computer's Turn Score: " << p2Score[1] << endl;

			//If the computer can win, loses their points, or has gotten 25 or more points
			if ((p2Score[0] + p2Score[1]) >= 100 || p2Score[1] == 0 || p2Score[1] >= 25) {
				//Flip turns
				playerOneTurn = !playerOneTurn;
				p2Score[0] = p2Score[0] + p2Score[1];
				p2Score[1] = 0;
				cout << "Computer's Total Score: " << p2Score[0] << endl;
				cout << "-----" << endl;
			}
		}
	}

	//Once the loop has broken, one of the players has reached the win condition
	//Therefore, check which player won.
	if (p1Score[0] >= 100) {
		cout << "You won this game! Congrats!" << endl;
	}
	else if (p2Score[0] >= 100) {
		cout << "The computer won the game! Better luck next time!" << endl;
	}

}

/**
	Uses a random function to simulate rolling a dice
	@return an integer value between 1 and 6
*/
int rollDie(void)
{
	//Gets a random die value between one and six
	int die = (rand() % 6) + 1;

	//Returns this value
	return die;
}

/**
	Checks to see if either dice rolls was a 0 and indicates if the turn score was lost
	@param die1value - the value of the first die rolled
	@param die2value - the value of the second die rolled
	@return a boolean value to indicate if the turn score should be abandoned
*/
bool isTurnScoreLost(int die1value, int die2value) {
	//Checks to see if either die value is  1
	if (die1value == 1 || die2value == 1) {
		//Return true if one or two ones
		cout << "One or more dice roll(s) was a 1, the turn was lost" << endl;
		return true;
	}
	//Returns false if neither roll was a one
	return false;
}

/**
	Checks to see if both dice rolls were 0s and indicates if the game was lost
	@param die1value - the value of the first die rolled
	@param die2value - the value of the second die rolled
	@return a boolean value to indicate if the game score should be abandoned
*/
bool isGameScoreLost(int die1value, int die2value) {
	//Checks to see if both die values are 1
	if (die1value == 1 && die2value == 1) {
		//Returns true if both dice are one
		cout << "Both dice rolls were 1s, the total score was lost" << endl;
		return true;
	}
	//Returns false if there's no ones
	return false;
}

/**
	Recieves user input until a valid choice (roll or stop) is made
	@return either a 'r' or 's' character to indiciate whether the user wants to roll or stop
*/
char getUserInput(void) {
	char userValue = ' ';

	do {
		cout << "Would you like to (r)oll again or (s)top?  ";
		cin >> userValue;
		userValue = tolower(userValue);
	} while (userValue != 'r' && userValue != 's');

	return userValue;
}
