//
//  digitStripper.cpp
//  digitStripperProgram
//
//  Created by Stephany Coffman-Wolph on 9/3/20.
//  Copyright © 2020 Stephany Coffman-Wolph. All rights reserved.
//

// This program pulls out the individual digits from a large
// integer number using math

// The second part of the program does so as a string

// Either is valid. Either is useful. Either is correct. Just depends on
// what makes sense to you. How you want to use it, how you design your
// program, etc.

#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    
    // Using Math
    int number = 12345678; // Sample number
    
    // This will start at the back of the number (i.e., last digit)
    // NOTE: This technique will permenately change the variable number
    // So if you need the digits multiple times, you will need to have multiple
    // copies of the original or save each digit in a separate variable
    for(int i = 1; i <= 8; i++) {
        int digit = number % 10; // pull last digit
        cout << digit << endl;   // display so you can see it working
        number = number / 10;    // get rid of that digit
    }
    
    
    // Using a String
    // This technique does not change the original copy or alter the string version
    // so this is easier if you need to read things multiple times
    // BUT numb[i] are NOT numbers any more so you need to convert back
    // before doing math
    int secondNumber = 12345678;
    string numb = to_string(secondNumber); // convert to a string
    
    // This will start at the back of the number (i.e., last digit)
    for(int i = 7; i >= 0; i--) {
        cout << numb[i] << endl;           // look at each character individually
    }
    
    // This will start at the beginning of the number (i.e., first digit)
    for(int i = 0; i < 8; i++) {
        cout << numb[i] << endl;           // look at each character individually
    }
    
    // Converting back to integer...
    int digit1 = stoi(numb.substr(0, 1));
    cout << "digit1 = " << digit1 << endl;
    
    int digit2 = stoi(numb.substr(1, 1));
    cout << "digit2 = " << digit2 << endl;
    
    // you woudl need to do this (or a similar process) for each digit
    // for example, you could put this into a loop
    
    return 0;
}
