#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#include "Item.h"
#include "Consumable.h"

//imran
Consumable::Consumable() {
	quantity = 0;
	unitPrice = 0;
}

//imran
Consumable::~Consumable() {};

//imran, ahmad
int Consumable::getNextID() {
	int static count = 0;
	return count++;
}

//imran, ahmad
bool Consumable::inputData() {
	Item::inputData(getNextID());
	cout << "quantity : ";
	cin >> quantity;
	cout << "Unit Price : RM ";
	cin >> unitPrice;
	return true;
}

//imran
int Consumable::getQuantity() {
	return quantity;
}

//imran
double Consumable::getUnitPrice() {
	return unitPrice;
}

//ahmad, imran
// The label when displaying a Consumable list
void Consumable::printListLabel() {
	cout << "\033[31m+-------------------------------------------------------------------------+\033[0m\n";
	cout << "\033[31m| "
		<< left << setw(6) << "ID" << "| "
		<< setw(20) << "NAME" << "| "
		<< setw(20) << "QUANTITY" << "| "
		<< setw(20) << "UNIT PRICE RM"
		<< "|\033[0m\n";
	cout << "\033[31m+-------------------------------------------------------------------------+\033[0m\n";
}

//ahmad, imran
void Consumable::printListItem() {
	cout << "| "
		<< left << setw(6) << getID() << "| "
		<< setw(20) << getName() << "| "
		<< setw(20) << getQuantity() << "| "
		<< setw(20) << getUnitPrice()
		<< "|\n";
}