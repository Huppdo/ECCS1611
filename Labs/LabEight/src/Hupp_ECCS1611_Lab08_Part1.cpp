// Dominic Hupp - 10/10/20 - Lab 8 Part 1
// Reads in a string from user and counts the vowels

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int countVowels(string str);
bool checkVowels(char inputChar);

int main(void) {
    string input;
    while (true) {
        cout << "Enter a string or Q to quit: ";
        getline(cin, input);
        if (input == "Q")
            break;
        //cout << "\"" << input << "\"" << endl;
        cout << "Vowel count: " << countVowels(input) << endl;
    }
    return 0;
}

int countVowels(string str) {
    int counter = 0;
    for (int i = 0; i < str.length(); i++) {
        counter = checkVowels(str[i]) ? counter + 1 : counter;
    }
    return counter;
}

bool checkVowels(char inputChar) {
    inputChar = tolower(inputChar);

    if (inputChar == 'a' || inputChar == 'e' || inputChar == 'i' || inputChar == 'o' || inputChar == 'u') {
        return true;
    }

    return false;
}