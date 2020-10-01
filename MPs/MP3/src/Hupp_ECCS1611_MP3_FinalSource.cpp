//Dominic Hupp - ECCS1611 - ECCS1611_MP3.cpp - 10/1/20
/*
	Allows for a two player version of tic tac toe to be played
	Players can enter their names and will switch first player every game
*/

#include <iostream>
#include <string>
using namespace std;

const int SIZE = 3;
const char charX = 'X';
const char charO = 'O';

int getPlayerInput(string playerName);
string getUsername(string defaultIdentify);
bool getPlayAgain(void);
bool isLegalMove(char board[SIZE][SIZE], int location);
void placeMarkOnBoard(char board[SIZE][SIZE], char playerMark, int location);	
void clearBoard(char board[SIZE][SIZE]);
bool hasThreeInRow(char board[SIZE][SIZE], char playerMark);
bool checkTie(char board[SIZE][SIZE]);
void locationToBoardLocation(int location, int& row, int& column);
void displayBoard(char board[SIZE][SIZE]);
void displayWinner(string playerName, bool tie);
void displayGameStats(int ties, int player1Score, int player2Score, string player1Name, string player2Name);

int main(void) {
	//Establish the board
	char board[SIZE][SIZE] = {
		{'1', '2', '3'},
		{'4', '5', '6'},
		{'7', '8', '9'}
	};

	//Setup first player swapping
	bool pOneX = true;

	//Setup score array where array[0] is p1 score, array[1] is p2 score, and array[2] is ties
	int scores[3] = { 0, 0, 0 };

	//Set the game run state
	bool gamesRunning = true;

	//Get usernames
	string usernameOne = getUsername("Player One");
	string usernameTwo = getUsername("Player Two");

	//Main game logic loop. This has a break at the bottom for if the player wants to end
	while (gamesRunning) {

		//Setup a variable to represent win condition
		bool winConditionMet = false;

		//Setup turn tracking
		bool xTurn = true;

		//Loop the game until the win condition is met
		while (!winConditionMet) {

			//Show the board to the current player
			displayBoard(board);

			//Get user input for this turn 
			int input = getPlayerInput(xTurn ? (pOneX ? usernameOne : usernameTwo) : (pOneX ? usernameTwo: usernameOne));

			//If the move was illegal, repeat the loop from the top
			if (!isLegalMove(board, input)) {
				continue;
			}

			//Since the move was legal, place the mark onto the board
			placeMarkOnBoard(board, (xTurn ? charX : charO), input);

			//Check to see if the player won or a tie was reached
			if (hasThreeInRow(board, (xTurn ? charX : charO)) || checkTie(board)) {
				//Set win true
				winConditionMet = true;
			} 
			else {
				//Flip the turn to the opposite player
				xTurn = !xTurn;
			}
		}

		//Displays the final game board
		displayBoard(board);

		//Checks to see if the game resulted in a tie
		if (checkTie(board) && !hasThreeInRow(board, (xTurn ? charX : charO))) {
			scores[2] += 1;
			displayWinner(" ", true);
		}
		else {
			//Adds points to the winner
			//If it was the X players turn upon winning
			if (xTurn) {
				if (pOneX) {
					displayWinner(usernameOne, false);

					//If player one was x this round, add one to their score
					scores[0] += 1;
				}
				else {
					displayWinner(usernameTwo, false);

					//Else, add one to player two's score
					scores[1] += 1;
				}
			}
			else {
				if (pOneX) {
					displayWinner(usernameTwo, false);

					//If player one was x this round, add one to player two's score
					scores[1] += 1;
				}
				else {
					displayWinner(usernameOne, false);

					//Else, add one to player one's score
					scores[0] += 1;
				}
			}
		}
		
		//Displays game stats and resets the board
		pOneX = !pOneX; //Flips the initial player
		displayGameStats(scores[2], scores[0], scores[1], usernameOne, usernameTwo);
		clearBoard(board);

		//Prompts user to play again
		gamesRunning = getPlayAgain();
	}

}

/** 
	This function displays the board onto the screen

	@param board - Takes in the board to display
*/
void displayBoard(char board[SIZE][SIZE]) {
	cout << endl << endl;

	//Iterates through the rows of the board
	for (int i = 0; i < 3; i++) {

		//Iterate and display the columns
		for (int j = 0; j < 3; j++) {
			cout << " " << board[i][j] << " |";
		}

		//Remove the final pipe character
		cout << "\b ";
		cout << endl;

		//Add a horizontal line between each row
		for (int k = 0; k < 11; k++) {
			//If the outer loop is on the first or second pass
			if (i < 2) {
				cout << "-";
			}
		}
		cout << endl;
	}
}

/**
	This function allows the user to input a value to place their piece

	@param playerName - The name of the user currently playing
	@return an integer representing the location on the board to place 
*/
int getPlayerInput(string playerName) {
	int location = -1;

	//Loop until the input is in the valid range
	do {
		cout << playerName << ", where would you like to place your marker? - ";
		cin >> location;
	} while (location < 1 || location > 9);

	return location;
}

/**
	This function uses pass by reference to convert the input location to
	a set of board coordinates

	@param location - The user input value of where to place their marker
*/
void locationToBoardLocation(int location, int& row, int& column) {
	location = location - 1;
	column = location % SIZE;
	row = (location - (location % SIZE)) / SIZE;
}

/**
	This function determines if the user chose an empty location to place
	their marker

	@param board - The tic tac toe board 2D array
	@param location - The raw user input of where to put their marker
*/
bool isLegalMove(char board[SIZE][SIZE], int location) {
	int legalRow = -1;
	int legalCol = -1;

	//Translates the location to coordinates
	locationToBoardLocation(location, legalRow, legalCol);

	//If the board has an X or O in that spot, return false for a legal move
	if (board[legalRow][legalCol] == charX || board[legalRow][legalCol] == charO) {
		return false;
	}

	return true;
}

/**
	Places the provided player marker onto the corresponding location on the board

	@param board - The tic tac toe board 2D array
	@param playerMark - The X/O mark of the current player
	@param location - The raw user input of where to put their marker
*/
void placeMarkOnBoard(char board[SIZE][SIZE], char playerMark, int location)  {
	int row = -1;
	int col = -1;

	//Translates the location to coordinates
	locationToBoardLocation(location, row, col);

	//Set the player mark onto the board
	board[row][col] = playerMark;
}

/**
	Checks to see if the player reached a win condition

	@param board - The tic tac toe board 2D array
	@param playerMark - The X/O mark of the current player
*/
bool hasThreeInRow(char board[SIZE][SIZE], char playerMark) {

	const int WINCOMBOS = 8;

	//Establish all the winning combinations per row value
	int winPatternsRow[WINCOMBOS][SIZE] = {
		{0, 0, 0}, //Top Row
		{1, 1, 1}, //Middle Row
		{2, 2, 2}, //Bottom Row
		{0, 1, 2}, //LtoR diagonal
		{0, 1, 2}, //RtoL diagonal
		{0, 1, 2}, //Left column
		{0, 1, 2}, //Middle column
		{0, 1, 2}  //Right column
	};

	//Establish all the winning combinations per column value
	int winPatternsCol[WINCOMBOS][SIZE] = {
		{0, 1, 2}, //Top Row
		{0, 1, 2}, //Middle Row
		{0, 1, 2}, //Bottom Row
		{0, 1, 2}, //LtoR diagonal
		{2, 1, 0}, //RtoL diagonal
		{0, 0, 0}, //Left column
		{1, 1, 1}, //Middle column
		{2, 2, 2}  //Right column
	};

	//Iterate through all the win conditions
	for (int i = 0; i < WINCOMBOS; i++) {
		if (board[winPatternsRow[i][0]][winPatternsCol[i][0]] == playerMark &&
			board[winPatternsRow[i][1]][winPatternsCol[i][1]] == playerMark &&
			board[winPatternsRow[i][2]][winPatternsCol[i][2]] == playerMark) {
			//If all 3 of the win condition values are true, return true for win
			return true;
		}
	};
	
	//Return false if all else fails
	return false;
}

/**
	Checks to see if there is any valid moves left

	@param board - The tic tac toe board 2D array
*/
bool checkTie(char board[SIZE][SIZE]) {
	//Iterates through the columns and rows
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {

			//If the board value isn't an X or O, return not a tie
			if (board[i][j] != charX && board[i][j] != charO) {
				return false;
			}
		}
	}
	//Return tie
	return true;
}

/**
	This function resets the board into the numerical values displayed
	at the beginning

	@param board - Takes in the board to display
*/
void clearBoard(char board[SIZE][SIZE]) {
	//Iterates through the columns and rows
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			//Sets the current 2D array value to the corresponding number that belongs inside

			board[i][j] = (char)((3 * i) + (j + 1) + 48); //Have to shift the numbers to fit in the ascii table
		}
	}
}

/**
	Prompts the current player to enter a username

	@param defaultIdentify - A string to display when the user is greeted
	@return a string representing the chosen username
*/
string getUsername(string defaultIdentify) {
	string username = "";

	//Continues to prompt user until they enter a non-blank username
	do {
		cout << defaultIdentify << ", enter your chosen username: ";
		getline(cin, username);
	} while (username == "" || username == " ");

	return username;
}

/**
	Prompts the users to see if they would like to play again

	@return a boolean value to determine if the games should continue running
*/
bool getPlayAgain(void) {
	char playAgain = ' ';

	//Run this loop until the user enters a valid character
	do {
		cout << "Would you like to (p)lay again or (q)uit? - ";
		cin >> playAgain;
		cin.clear();
		playAgain = tolower(playAgain);
	} while (playAgain != 'p' && playAgain != 'q');

	//Checks to see if the player entered quit
	return (playAgain == 'q' ? false : true);
}

/**
	Displays the overall stats of a game

	@param ties - The number of tied games in this series
	@param player1Score - The total score of the first player
	@param player2Score - The total score of the second player
	@param player1Name - The chosen username of the first player
	@param player2Name - The chosen username of the second player
	
*/
void displayGameStats(int ties, int player1Score, int player2Score, string player1Name, string player2Name) {
	cout << endl << endl;

	cout << "Ties - " << ties << endl;
	cout << player1Name << "'s wins - " << player1Score << endl;
	cout << player2Name << "'s wins - " << player2Score << endl;
}

/**
	This function outputs a display message for the winner

	@param playerName - The name of the user currently playing
*/
void displayWinner(string playerName, bool tie) {
	if (tie) {
		cout << "The game ended in a tie." << endl;
	} else {
	cout << "Congrats, " << playerName;
	cout << "! You won!" << endl;
	}
}