#include <iostream>
#include <string>
using namespace std;
#include "Item.h"

Item::Item() {
	id = 0;
	name = "sape saye";
}

Item::~Item() {}

int Item::getNextID() {
	int static count = 0;
	return count++;
}

void Item::inputData() {
	id = getNextID();
	cin.ignore(1, '\n');
	cout << "name : ";
	getline(cin, name);
}


int Item::getID() {
	return id;
}

void Item::setID(int n) {
	id = n;
}

string Item::getName() {
	return name;
}

