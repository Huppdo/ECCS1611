//Dominic Hupp - ECCS1611 - 
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{	
    //Ask the user to enter a string, find the length of a string, determine if the length is even or odd
    string userInput = "";
    cout << "Please enter your string to determine if the length is even or odd: ";
    cin >> userInput;
    if (userInput.length() % 2 == 0) {
        cout << "Your string is even!" << endl;
    } else if (userInput.length() % 2 == 1) {
        cout << "Your string is odd!" << endl;
    }
    cout << endl << endl;

    //Ask the user to enter a string, display the middle character of the string if odd or the middle 2 if even
    string providedInput = "";
    providedInput = userInput;
    cout << "Using string from problem #1 (" << providedInput << ")" << endl;
    cout << "The middle section of your string is: ";
    if (providedInput.length() % 2 == 0) {
        cout << providedInput.substr((providedInput.length()-1) / 2, 2) << endl;
    }
    else if (providedInput.length() % 2 == 1) {
        cout << providedInput.substr((providedInput.length())/2, 1) << endl;
    }
    cout << endl << endl;

    //Ask the user to enter a zip code, verify the zip code is the correct length and display an appropriate message
    string zipCode = "";
    cout << "Please enter your zip code (XXXXX):  ";
    cin >> zipCode;

    if (zipCode.length() == 5) {
        cout << "Thank you!" << endl;
    }
    else if (zipCode.length() > 5) {
        cout << "Your zip code has too many numbers!" << endl;
    }
    else if (zipCode.length() < 5) {
        cout << "Your zip code is too short!" << endl;
    }
    cout << endl << endl;

    //Ask the user for a numerical grade. Display the cooresponding letter grade. Also display "Invalid" for grades under 0
    double numericalGrade = 0;
    cout << "Please enter a numerical grade: ";
    cin >> numericalGrade;

    if (numericalGrade < 0) {
        cout << "That grade is invalid" << endl;
    } else if (numericalGrade < 60) {
        cout << "The student recieved an F" << endl;
    } else if (numericalGrade < 70) {
        cout << "The student recieved a D" << endl;
    } else if (numericalGrade < 80) {
        cout << "The student recieved a C" << endl;
    } else if (numericalGrade < 90) {
        cout << "The student recieved a B" << endl;
    } else if (numericalGrade <= 100) {
        cout << "The student recieved an A" << endl;
    }
    cout << endl << endl;

    //Ask the user to enter an int in the range 1-9. Display congrats if successful, an error if not
    int numericalRangeInput = 0;
    cout << "Please enter an int in the range 1-9: ";
    cin >> numericalRangeInput;
    if (numericalRangeInput < 1 || numericalRangeInput > 9) {
        cout << "Your number was not in the range!" << endl;
    }
    else {
        cout << "Congrats! Your number is in the range" << endl;
    }
    cout << endl << endl;

    /*
    Ask the user to enter a character in the range of 'a' through 'e'. If outside, display error. 
    Else, if 'a' or 'b', display "Correct Answer", else display "Wrong Answer"
    */
    char userChar;
    cout << "Please enter a character in the range 'a' through 'e': ";
    cin >> userChar;
    if (userChar == 'c' || userChar == 'd' || userChar == 'e') {
        cout << "Wrong Answer!" << endl;
    }
    else if (userChar == 'a' || userChar == 'b') {
        cout << "Correct Answer!" << endl;
    }
    else {
        cout << "Error! Your character is not in the provided range" << endl;
    }
    cout << endl << endl;
}