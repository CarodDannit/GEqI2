#include <iostream>
#include <string>
using namespace std;
#include "Item.h"
//ahmad was here

Item::Item() {
	id = 0;
	name = "sape saye";
}

Item::~Item() {}

void Item::inputData(int id) {
	Item::id = id;
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

