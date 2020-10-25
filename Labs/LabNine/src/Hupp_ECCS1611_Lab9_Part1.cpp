//Dominic Hupp - ECCS1611 - 10/22/20
//Assigns passenger seats on an airplane

#include <iostream>
#include <string>
using namespace std;

struct airplaneRow {
	string rowNumber = "";
	bool seatA = false;
	bool seatB = false;
	bool seatC = false;
	bool seatD = false;
};

const int ROWS = 13;
airplaneRow airplane[] = {
	{" 1"},
	{" 2"},
	{" 3"},
	{" 4"},
	{" 5"},
	{" 6"},
	{" 7"},
	{" 8"},
	{" 9"},
	{"10"},
	{"11"},
	{"12"},
	{"14", false, false, true, true }
};

void displayPlane();
void addSpace();
void getUserInput(int& row, char& seat);
void markSeat(int row, char seat);
bool checkSeat(int row, char seat);
bool checkEmpty();

int main() {
	int row = -1;
	char seat = ' ';

	cout << "Welcome to Dominic Air's plane filling interface." << endl;
	cout << "Please follow all directions as they appear." << endl;
	cout << "Feel free to enter seat 0Z at any time to quit filling" << endl << endl;
	displayPlane();

	while (checkEmpty()) {
		getUserInput(row, seat);
		if (checkSeat(row, seat)) {
			cout << "That seat is occupied and/or does not exist. Please try again" << endl;
			continue;
		}
		if (row == 0 && seat == 'Z') {
			break;
		}
		markSeat(row, seat);
		addSpace();
		displayPlane();
	}
}

void displayPlane() {
	for (int i = 0; i < ROWS-1; i++) {
		cout << airplane[i].rowNumber << "   ";
		cout << (airplane[i].seatA ? 'X' : 'A') << " ";
		cout << (airplane[i].seatB ? 'X' : 'B') << "     ";
		cout << (airplane[i].seatC ? 'X' : 'C') << " ";
		cout << (airplane[i].seatD ? 'X' : 'D') << endl;
	}
	cout << airplane[ROWS-1].rowNumber << "   ";
	cout << (airplane[ROWS - 1].seatA ? 'X' : 'A') << " ";
	cout << (airplane[ROWS - 1].seatB ? 'X' : 'B') << endl << endl;
}

void addSpace() {
	for (int i = 0; i < 25; i++) {
		cout << endl;
	}
}

void markSeat(int row, char seat) {
	if (row == 13) {
		row = row - 2;
	}
	else {
		row = row - 1;
	}
	switch(seat) {
		case 'A':
			airplane[row].seatA = true;
			break;
		case 'B':
			airplane[row].seatB = true;
			break;
		case 'C':
			airplane[row].seatC = true;
			break;
		case 'D':
			airplane[row].seatD = true;
			break;
	}
}

bool checkEmpty() {
	bool empty = false;
	for (int i = 0; i < ROWS - 1; i++) {
		if (!airplane[i].seatA || !airplane[i].seatB || !airplane[i].seatC || !airplane[i].seatD) {
			empty = true;
		}
	}
	if (!airplane[ROWS-1].seatA || !airplane[ROWS-1].seatB) {
		empty = true;
	}
	return empty;
}

bool checkSeat(int row, char seat) {
	if (row == 13) {
		row = row - 2;
	}
	else {
		row = row - 1;
	}

	if (row < 0 || row > 12) {
		return true;
	}

	if (row == 12 && (seat == 'C' || seat == 'D')) {
		return true;
	}

	switch (seat) {
	case 'A':
		return airplane[row].seatA;
	case 'B':
		return airplane[row].seatB;
	case 'C':
		return airplane[row].seatC;
	case 'D':
		return airplane[row].seatD;
	default:
		return true;
	}
}

void getUserInput(int& row, char& seat) {
	string resp = "";
	cout << "Insert the desired row and seat (or enter 0Z to quit): ";
	getline(cin, resp);
	if (resp.length() == 3) {
		row = stoi(resp.substr(0, 2));
		seat = resp.at(2);
	}
	else {
		row = stoi(resp.substr(0, 1));
		seat = resp.at(1);
	}
}