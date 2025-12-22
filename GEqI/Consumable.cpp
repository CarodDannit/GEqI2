#include <iostream>
#include <string>
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
