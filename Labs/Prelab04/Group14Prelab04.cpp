//Group 14 - ECCS1611 - Prelab 04


#include <iostream>


using namespace std;

int main() {
    //Get the users credit card
    int userCard = -1;
    int userArray[8];
    cout << "Insert your card number here: ";
    cin >> userCard;

    //If the card wasn't an integer
    if (cin.fail()) {
        return 1;
    }

    //Verify card information
    if (userCard < 10000000 || userCard > 99999999) {
        cout << "Your credit card number was not valid.";
        return 1;
    }

    //Seperate digits
    for (int i = 0; i < 8; i++) {
        userArray[7 - i] = userCard % 10;
        userCard = userCard / 10;
    }

    int evenNumbers = 0;
    int oddNumbers = 0;

    evenNumbers = userArray[1] + userArray[3] + userArray[5] + userArray[7];

    for (int i = 0; i < 8; i = i + 2) {
        oddNumbers += (userArray[i] * 2) < 10 ? userArray[i]*2 : (userArray[i]*2 % 10) + 1;
        cout << oddNumbers << endl;
    }
    cout << evenNumbers << ", " << oddNumbers << endl;

    if ((evenNumbers + oddNumbers) % 10 == 0) {
        cout << "You have a valid card";
    }
    else {
        cout << "You have an invalid card";
    }
}