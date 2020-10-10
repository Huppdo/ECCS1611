// Dominic Hupp - 10/10/20 - Lab 8 Part 3
// Reads in a string of Roman Numerals from user and prints a decimal representation

#include <iostream>
#include <string>

using namespace std;

int romanCharValue(char r);
int convertRomanToInt(string s);

int main(void) {
    string input;
    while (true) {
        cout << "Enter a string or Q to quit: ";
        getline(cin, input);
        if (input == "Q")
            break;
        //cout << "\"" << input << "\"" << endl;
        cout << input << " = " << convertRomanToInt(input) << endl;
    }
    return 0;
}

int romanCharValue(char r) {
    r = toupper(r);
    switch (r) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
             return 0;
    }
}

int convertRomanToInt(string s) {
    int total = 0;
    while (s.length() >= 1) {
        if (s.length() == 1 || romanCharValue(s[0]) >= romanCharValue(s[1])) {
            total += romanCharValue(s[0]);
            s.erase(0, 1);
        }
        else {;
        total = total + (romanCharValue(s[1]) - romanCharValue(s[0]));
        s.erase(0, 2);
        }
    }
    return total;
}