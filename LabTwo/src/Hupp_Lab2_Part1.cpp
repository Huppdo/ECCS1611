//Dominic Hupp - ECCS 1611 Lab Two - Part One

#include <iostream>
#include <string>
using namespace std;

int main()
{
	cout << "Hello, my name is Hal! \n" << "What is your name? ";
	string user_name;
	getline(cin, user_name);

	cout << "Hello, " << user_name << ". I am glad to meet you!";
}