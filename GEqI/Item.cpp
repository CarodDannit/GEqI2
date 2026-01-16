#include <iostream>
#include <string>
using namespace std;
#include "Item.h"

//imran
Item::Item() {
	id = 0;
	name = "sape saye";
}

//imran
Item::~Item() {}

//imran
void Item::inputData(int id) {
	Item::id = id;
	cin.ignore(1, '\n');
	cout << "name : ";
	getline(cin, name);
}

//imran
int Item::getID() {
	return id;
}

//imran
void Item::setID(int n) {
	id = n;
}

//imran
string Item::getName() {
	return name;
}