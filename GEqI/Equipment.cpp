#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#include "Item.h"
#include "Equipment.h"

//imran
Equipment::Equipment() {
	category = "unknown";
	status = "available";
	condition = "good";
}

//imran
Equipment::~Equipment() {}

//imran, ahmad
int Equipment::getNextID() {
	int static count = 0;
	return count++;
}

//imran, ahmad
bool Equipment::inputData() {
	Item::inputData(getNextID());
	cout << "category : ";
	cin >> category;
	cout << "status : ";
	cin >> status;
	cout << "condition : ";
	cin >> condition;
	return true;
}

//imran
string Equipment::getCategory() {
	return category;
}

//imran
string Equipment::getStatus() {
	return status;
}

//imran
string Equipment::getCondition() {
	return condition;
}

//ahmad, imran
// The label when displaying an Equipment list
void Equipment::printListLabel() {
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

//ahmad, imran
void Equipment::printListItem() {
	cout << "| "
		<< left << setw(6) << getID() << "| "
		<< setw(20) << getName() << "| "
		<< setw(20) << getCategory() << "| "
		<< setw(20) << getStatus() << "| "
		<< setw(20) << getCondition()
		<< "|\n";
}