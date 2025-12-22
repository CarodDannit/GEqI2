#include <iostream>
#include <string>
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
