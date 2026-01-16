#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#include "List.h"
#include "Maintenance.h"
List<Equipment>* Maintenance::equipmentList;

//imran
Maintenance::Maintenance() {
	id = 0;
	equip.setID(0);
	issue = "nothing";
	cost = 0;
	date = "1/1/2026";
	status = "pending";
}

//imran
Maintenance::~Maintenance(){}

//ahmad
void Maintenance::setEquipments(List<Equipment>& eqpList) {
	equipmentList = &eqpList;
}

//imran, ahmad
int Maintenance::getNextID() {
	int static count = 0;
	return count++;
}

//imran
void Maintenance::setID(int n) {
	id = n;
}

//imran, ahmad
bool Maintenance::inputData() {
	id = getNextID();
	int n;
	int loc;

	cout << "equip id : ";
	cin >> n;
	if (equipmentList->SearchItem(n, loc, 1)) {
		cout << "Equipment found!" << endl;
		equip.setID(n);
	}
	else {
		cout << "Equipment not found!" << endl;
		return false;
	}
	
	cin.ignore(1, '\n');
	cout << "issue : ";
	getline(cin, issue);
	cout << "cost maintenance : ";
	cin >> cost;
	cout << "date : ";
	cin >> date;
	cout << "status : ";
	cin >> status;
	return true;
}

//imran
int Maintenance::getID() {
	return id;
}

//imran
int Maintenance::getEquipID() {
	return equip.getID();
}

//imran
string Maintenance::getIssue() {
	return issue;
}

//imran
double Maintenance::getCost() {
	return cost;
}

//imran
string Maintenance::getDate() {
	return date;
}

//imran
string Maintenance::getStatus() {
	return status;
}

//ahmad, imran
void Maintenance::printListLabel() {
	cout << "\033[31m+----------------------------------------------------------------------------------------------+\033[0m\n";
	cout << "\033[31m| "
		<< left << setw(6) << "ID" << "| "
		<< setw(6) << "EQ ID" << "| "
		<< setw(25) << "ISSUE" << "| "
		<< setw(15) << "COST" << "| "
		<< setw(15) << "DATE" << "| "
		<< setw(15) << "STATUS"
		<< "|\033[0m\n";
	cout << "\033[31m+----------------------------------------------------------------------------------------------+\033[0m\n";
}

//ahmad, imran
void Maintenance::printListItem() {
	cout << "| "
		<< left << setw(6) << getID() << "| "
		<< setw(6) << getEquipID() << "| "
		<< setw(25) << getIssue() << "| "
		<< setw(15) << getCost() << "| "
		<< setw(15) << getDate() << "| "
		<< setw(15) << getStatus()
		<< "|\n";
}