//Dominic Hupp - ECCS1611 - 10/22/20
//Checks the validity of credit cards

#include <iostream>
#include <string>
using namespace std;

bool isCardValid(int digits[], int size);
void splitString(int arraySmall[8], int arrayLarge[16], string card);
string getCard();

int main() {
	string cardString = "";
	while (true) {
		cardString = getCard();
		if (cardString == "Q") {
			break;
		}

		int digits16[16];
		int digits8[8];

		splitString(digits8, digits16, cardString);
		if (isCardValid((cardString.length() == 8 ? digits8 : digits16), cardString.length())) {
			cout << "Card is valid" << endl;
		}
		else {
			cout << "Card is invalid" << endl;
		}
	}
}

string getCard() {
	string ansStr = "";
	do {
		cout << "Please enter a card number or Q to quit: ";
		getline(cin,ansStr);
	} while (ansStr.length() != 1 && ansStr.length() != 8 && ansStr.length() != 16);
	return ansStr;
}

void splitString(int arraySmall[8], int arrayLarge[16], string card) {
	if (card.length() == 8) {
		for (int i = 0; i < 8; i++) {
			arraySmall[i] = (int)card.at(i) - 48;
		}
	}
	else {
		for (int i = 0; i < 16; i++) {
			arrayLarge[i] = (int)card.at(i) - 48;
		}
	}
}

bool isCardValid(int digits[], int size) {
	int total = 0;
	for (int i = size - 1; i > -1; i--) {
		//cout << digits[i];
		if (i % 2 == 1) {
			//cout << "Adding" << endl;
			total += digits[i];
		}
		else {
			int temp = digits[i] * 2;
			if (temp < 10) {
				total += temp;
			}
			else {
				total += 1;
				total += (temp - 10);
			}
		}
	}
	return (total % 10 == 0);
}
