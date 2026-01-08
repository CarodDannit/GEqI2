#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#include "List.h"
#include "Item.h"
#include "Equipment.h"
#include "Consumable.h"
#include "Maintenance.h"
#include "SampleData.h"



int main() {
	cout << "\033[31m||===== GEqI - Gym Equipment Inventory System =====||\033[0m\n";
	cout << endl;

	List<Equipment> eqp1;
	List<Consumable> cnm1;
	List<Maintenance> mnc1;
	int optionMenu, optionAdd, optionDisplay, methodSearch, optionSearch, optionMnc, asc;
	insertSampleData(eqp1, cnm1);
	do {

		cout << "1:display\n2:add\n3:delete\n4:sort\n5:search\n6:maintenance\n7:exit\n";
		cout << "option : ";
		cin >> optionMenu;
		system("cls");
		switch (optionMenu) {
		case 1: //display equipment and consumable...
			cout << "\033[32mdisplay item\033[0m" << endl;
			cout << "1:equipment\n2:consumable" << endl;
			cout << "option : ";
			cin >> optionDisplay;
			system("cls");

			if (optionDisplay == 1) eqp1.printList();
			else if (optionDisplay == 2) cnm1.printList();
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
		
		case 5: {
			int targetID, location;
			cout << "\033[32msearch item\033[0m" << endl;
			cout << "1. equipment\n";
			cout << "2. consumable\n";
			cin >> optionSearch;
			system("cls");
			if (optionSearch > 2) break;
			

			cout << "\033[32mPick search method\033[0m:\n";
			cout << "1. Sentinel Search\n";
			cout << "2. Binary Search\n";
			cin >> methodSearch;
			system("cls");
			if (methodSearch > 2) break;
			

			cout << "Enter ID to search: ";
			cin >> targetID;

			
			bool found = false;
			if (optionSearch == 1) {
				if (methodSearch == 1) {
					found = eqp1.SearchItem(targetID, location);
					if (found) {
						cout << "\033[32mItem found at position: " << location << "\033[0m\n";
						eqp1.printSingle();
					}
					else {
						cout << "\033[31mItem not found\033[0m\n";
					}
				}
			}
			else if (optionSearch == 2) {
				if (methodSearch == 1) {
					found = eqp1.SearchItem(targetID, location);
					if (found) {
						cout << "\033[32mItem found at position: " << location << "\033[0m\n";
						eqp1.printSingle();
					}
					else {
						cout << "\033[31mItem not found\033[0m\n";
					}
				}
			}
			break;
		}

		case 4: //selection sorting
			cout << "\033[32mdisplay item\033[0m" << endl;
			cout << "1:equipment\n2:consumable" << endl;
			cin >> optionDisplay;
			system("cls");
			if (optionDisplay > 2) break;


			cout << "1. Ascending\n";
			cout << "2. Descending\n";
			cout << "Choose order: ";
			cin >> asc;
			system("cls");
			if (asc > 2) break;

			if (optionDisplay == 1) { // EQUIPMENT
				if (asc == 1) eqp1.sortID(true);
				else if(asc == 2) eqp1.sortID(false);
				eqp1.printList(); // display after sorting
			}
			else if (optionDisplay == 2) { // CONSUMABLE
				if (asc == 1) cnm1.sortID(true);				
				else cnm1.sortID(false);
				cnm1.printList(); // display after sorting
			}
			break;


		case 6: //maintenance.. can add maintenance and maybe update status?
			cout << "\033[32mMaintenance\033[0m" << endl;
			cout << "1:display\n2:add\n3:update" << endl;
			cout << "option : ";
			cin >> optionMnc;
			system("cls");

			if (optionMnc == 1)  mnc1.printList();
			else if (optionMnc == 2) mnc1.AddMaintenance(eqp1);
			else if (optionMnc == 3) {}; //don't know to add what
			break;
		case 7: system("exit");
		default: return false;
		}

	} while (true);



	return 0;
}
