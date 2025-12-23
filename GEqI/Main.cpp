#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#include "List.h"
#include "Item.h"
#include "Equipment.h"
#include "Consumable.h"
#include "Maintenance.h"

//AHI AHMAD
//Genesis : 67

int main() {
	cout << "\033[31m||===== GEqI - Gym Equipment Inventory System =====||\033[0m\n";
	cout << endl;

	List<Equipment> eqp1;
	List<Consumable> cnm1;
	List<Maintenance> mnc1;
	int optionMenu, optionAdd, optionDisplay,optionSearch;

	do {

		cout << "1:display\n2:add\n3:delete\n4:sort\n5:search\n6:maintenance\n7:exit\n";
		cout << "option : ";
		cin >> optionMenu;
		system("cls");
		switch (optionMenu) {
		case 1: //display equipment and consumable
			cout << "\033[32mdisplay item\033[0m" << endl;
			cout << "1:equipment\n2:consumable" << endl;
			cout << "option : ";
			cin >> optionDisplay;
			system("cls");

			if (optionDisplay == 1) eqp1.printEquipment();
			else if (optionDisplay == 2) cnm1.printConsumable();
			break;

		case 2: //add item equipment and consumable
			cout << "\033[32madd item\033[0m" << endl;
			cout << "1:equipment\n2:consumable" << endl;
			cout << "option : ";
			cin >> optionAdd;
			system("cls");

			if (optionAdd == 1) eqp1.AddToFront();
			else if (optionAdd == 2) cnm1.AddToFront();
			break;

		case 3: //delete equipment and maybe consumable
			eqp1.DeleteFront(); 
			break;
		
		case 5: {//ada slaveowner dipaksa
			int jamal;
			cout << "Pick search method:\n";
			cout << "1. equipment\n";
			cout << "2. consumable\n";
			cin >> jamal;
			system("cls");
			cout << "1. Sentinel Search\n";
			cout << "2. Binary Search\n";
			cin >> optionSearch;
			system("cls");

			int targetID, location;
			cout << "Enter ID to search: ";
			cin >> targetID;

			bool found = false;
			if (jamal == 1) {
				if (optionSearch == 1) {
					found = eqp1.SearchItem(targetID, location);
					if (found) {
						cout << "\033[32mItem found at position: " << location << "\033[0m\n";
						eqp1.printSingleEquipment(targetID);
					}
					else {
						cout << "\033[31mItem not found\033[0m\n";
					}
				}
			}
			break;
		}

		case 6: //maintenance.. can add maintenance and maybe update status?
			int optionMnc;
			cout << "\033[32mMaintenance\033[0m" << endl;
			cout << "1:display\n2:add\n3:update" << endl;
			cout << "option : ";
			cin >> optionMnc;
			system("cls");

			if (optionMnc == 1)  mnc1.printMaintenance();
			else if (optionMnc == 2) mnc1.AddMaintenance(eqp1);
			else if (optionMnc == 3) {}; //don't know to add what
			break;
		case 7: system("exit");
		default: return false;
		}

	} while (true);



	return 0;
}
