#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#include "Item.h"
#include "Equipment.h"

Equipment::Equipment() {
	category = "unknown";
	status = "available";
	condition = "good";
}

Equipment::~Equipment() {}

void Equipment::inputData() {
	Item::inputData();
	cout << "category : ";
	cin >> category;
	cout << "status : ";
	cin >> status;
	cout << "condition : ";
	cin >> condition;
}

string Equipment::getCategory() {
	return category;
}

string Equipment::getStatus() {
	return status;
}

string Equipment::getCondition() {
	return condition;
}

void Equipment::printListLabel() { // The label when displaying an Equipment list
	cout << "\033[31m+-----------------------------------------------------------------------------------------------+\033[0m\n";
	cout << "\033[31m| "
		<< left << setw(6) << "ID" << "| "
		<< setw(20) << "NAME" << "| "
		<< setw(20) << "CATEGORY" << "| "
		<< setw(20) << "STATUS" << "| "
		<< setw(20) << "CONDITION"
		<< "|\033[0m\n";
	cout << "\033[31m+-----------------------------------------------------------------------------------------------+\033[0m\n";
}

void Equipment::printListItem() {
	cout << "| "
		<< left << setw(6) << getID() << "| "
		<< setw(20) << getName() << "| "
		<< setw(20) << getCategory() << "| "
		<< setw(20) << getStatus() << "| "
		<< setw(20) << getCondition()
		<< "|\n";
}