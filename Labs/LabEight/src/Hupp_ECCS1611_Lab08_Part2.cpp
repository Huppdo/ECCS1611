// Dominic Hupp - 10/10/20 - Lab 8 Part 2
// Reads in a string from user and counts the words

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int countWords(string str);

int main(void) {
    string input;
    while (true) {
        cout << "Enter a string or Q to quit: ";
        getline(cin, input);
        if (input == "Q")
            break;
        //cout << "\"" << input << "\"" << endl;
        cout << "Word count: " << countWords(input) << endl;
    }
    return 0;
}

int countWords(string str) {
    int counter = 1;
    bool space = false;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ') {
            space = true;
        }
        else {
            if (space) {
                counter += 1;
            }
            space = false;
        }
    }

    return counter;
}