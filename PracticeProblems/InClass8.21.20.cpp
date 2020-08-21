//Dominic Hupp - ECCS1611 - In Class Practice Problems 8/21/20

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{	
    //Constants
    const double PI = 3.14159;

    //Practice Problem #1 - Accept a radius and calculate the circumference
    double radiusCircle;
    cout << "Please add a radius to calculate the circumference for - ";
    cin >> radiusCircle;
    cout << "Your circumference is - " << (2 * PI * radiusCircle) << endl << endl;

    //Practice Problem #2 - Accept 4 numbers and average them
    double num1 = 0, num2 = 0, num3 = 0, num4 = 0;
    cout << "Please add 4 numbers seperated by spaces to average - ";
    cin >> num1 >> num2 >> num3 >> num4;
    cout << "Your average is - " << ((num1 + num2 + num3 + num4) / 4) << endl << endl;

    //Practice Problem #3 - Ask the user to input their area code & phone number;
    //Display them both to the screen in the format 1(XXX)XXX-XXXX
    string areaCode = "", phoneNumber = "";
    cout << "Please insert your area code [format: XXX] - ";
    cin >> areaCode;
    cout << "Please insert your phone number [format: XXX-XXXX] - ";
    cin >> phoneNumber;
    cout << "1(" << areaCode << ")" << phoneNumber << endl << endl;

    //Practice Problem #4 - Determine if an integer is even or odd
    int wholeNumber = 0;
    cout << "Please insert a whole number to determine if its even or odd - ";
    cin >> wholeNumber;
    if (wholeNumber % 2 == 0) {
        cout << "Your number (" << wholeNumber << ") is even!" << endl << endl;
    }
    else {
        cout << "Your number (" << wholeNumber << ") is odd!" << endl << endl;
    }

    //Practice Problem #5 - Ask the user to enter a 5 digit number. Echo/Display each digit on a seperate line
    string inputNumber = "";
    cout << "Insert a 5 digit number to be printed line by line - ";
    cin >> inputNumber;
    for (int i = 0; i < inputNumber.length(); i++) {
        cout << inputNumber[i] << endl;
    }
    cout << endl;

    //Practice Problem #6 - Madlibs; accept various user inputs and insert them into a madlibs
    string userName = "", userColor = "", userSnack = "";
    cout << "Insert your name, favorite color, and favorite snack (seperated by a space) - ";
    cin >> userName >> userColor >> userSnack;
    cout << "Hi " << userName << ", thank you for communicating with me today." << endl;
    cout << "Wow, your favorite color is " << userColor << ", that is my favorite color too." << endl;
    cout <<"Interesting favorite snack choice, I am not sure that I would enjoy " << userSnack << endl;

}
