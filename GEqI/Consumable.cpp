#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#include "Item.h"
#include "Consumable.h"


Consumable::Consumable() {
	quantity = 0;
	unitPrice = 0;
}

Consumable::~Consumable() {};

void Consumable::inputData() {
	Item::inputData();
	cout << "quantity : ";
	cin >> quantity;
	cout << "Unit Price : RM ";
	cin >> unitPrice;
}

int Consumable::getQuantity() {
	return quantity;
}

double Consumable::getUnitPrice() {
	return unitPrice;
}

void Consumable::printListLabel() { // The label when displaying a Consumable list
	cout << "\033[31m+----------------------------------------------------------+\033[0m\n";
	cout << "\033[31m| "
		<< left << setw(6) << "ID" << "| "
		<< setw(15) << "NAME" << "| "
		<< setw(15) << "QUANTITY" << "| "
		<< setw(15) << "UNIT PRICE RM"
		<< "|\033[0m\n";
	cout << "\033[31m+----------------------------------------------------------+\033[0m\n";
}

void Consumable::printListItem() {
	cout << "| "
		<< left << setw(6) << getID() << "| "
		<< setw(15) << getName() << "| "
		<< setw(15) << getQuantity() << "| "
		<< setw(15) << getUnitPrice()
		<< "|\n";
}