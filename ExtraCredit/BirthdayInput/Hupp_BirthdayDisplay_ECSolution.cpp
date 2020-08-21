//Dominic Hupp - ECCS1611 - Extra Credit Birthday String

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{	
    /*
    This code was faulty if the user inputs any spaces in addition to the format provided.
    Therefore, my plan is to strip out all spaces from the final answer.
    Also, using cin only takes up to a space, whereas getline will get everything until the newline char
    */
    for (int i = 0; i < 3; i++) {
    cout << "What is your birthdate? (XX/XX/XX)" << endl;
    string wholeBirthdate = "";
    getline(cin, wholeBirthdate);

    //Remove all whitespace from wholeBirthday string.
    while (wholeBirthdate.find(" ") != string::npos) {
        wholeBirthdate.erase(wholeBirthdate.begin() + wholeBirthdate.find(" "));
    }

    //Substr takes two args (starting index, length to include)
    string month = wholeBirthdate.substr(0, 2);
    string day = wholeBirthdate.substr(3,2);
    string year = wholeBirthdate.substr(6, 2);
    cout << month << " " << day << " " << year << endl << endl;
    }
}
