//Dominic Hupp - ECCS1611 - In Class Oct 19, 2020

#include <iostream>
#include <ctime>
#include <string>
using namespace std;

class ClockOfTheLongNow {
public:
	ClockOfTheLongNow();
	ClockOfTheLongNow(int year);
	void AddYear();
	int ShowYear();
private:
	int private_year = 0;
};

ClockOfTheLongNow::ClockOfTheLongNow() {
	struct tm timeinfo;
	time_t now = time(0);
	localtime_s(&timeinfo, &now);
	//cout << timeinfo.tm_year;
	private_year = 1900 + timeinfo.tm_year;
}

ClockOfTheLongNow::ClockOfTheLongNow(int year) {
	private_year = year;
}

void ClockOfTheLongNow::AddYear() {
	private_year += 1;
}

int ClockOfTheLongNow::ShowYear() {
	return private_year;
}

class PizzaPie {
public:
	PizzaPie();
	PizzaPie(int size, string type, double price);
	void display();
private:
	int pizzaSize;
	string pizzaType;
	double pizzaPrice;
};

PizzaPie::PizzaPie() {
	pizzaSize = 0;
	pizzaType = "None";
	pizzaPrice = 0;
}

PizzaPie::PizzaPie(int size, string type, double price) {
	pizzaSize = size;
	pizzaType = type;
	pizzaPrice = price;
}

void PizzaPie::display() {
	cout << "The pizza is " << pizzaSize << " inches in diameter\n";
	cout << "The pizza type is " << pizzaType << endl;
	cout << "The pizza costs " << pizzaPrice << endl;
}

int main() {
	cout << "Clock program starting" << endl;

	ClockOfTheLongNow basicYear;
	ClockOfTheLongNow currentYear(2020);

	cout << basicYear.ShowYear() << endl;
	cout << currentYear.ShowYear() << endl;

	currentYear.AddYear();
	basicYear.AddYear();

	cout << basicYear.ShowYear() << endl;
	cout << currentYear.ShowYear() << endl;
	cout << "Clock program ending..." << endl << endl;
	cout << "Pizza program starting" << endl;

	PizzaPie noPizza;
	PizzaPie myPizza(16, "Thin", 18.79);

	noPizza.display();
	myPizza.display();

	cout << "Pizza program ending";
}