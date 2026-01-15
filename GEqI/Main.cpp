#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Header files for list structure and item types
#include "List.h"
#include "Item.h"
#include "Equipment.h"
#include "Consumable.h"
#include "Maintenance.h"
#include "SampleData.h"

int main() {
    // Display system title
    cout << "\033[31m||===== GEqI - Gym Equipment Inventory System =====||\033[0m\n\n";

    // Create lists for each item type
    List<Equipment> eqp1;
    List<Consumable> cnm1;
    List<Maintenance> mnc1;

    // Link equipment list to maintenance for reference
    Maintenance::setEquipments(eqp1);

    // Variables for menu navigation
    int optionMenu, optionAdd, optionDisplay, optionSort;
    int methodSearch, optionSearch, optionMnc, asc;

    // Insert predefined sample data for testing
    insertSampleData(eqp1, cnm1);

    // Main menu loop
    do {
        cout << "1:display\n2:add\n3:delete\n4:sort\n5:search\n6:maintenance\n7:exit\n";
        cout << "option : ";
        cin >> optionMenu;
        system("cls");

        switch (optionMenu) {

        case 1: // Display equipment or consumable list
            cout << "\033[32mdisplay item\033[0m\n";
            cout << "1:equipment\n2:consumable\n";
            cin >> optionDisplay;
            system("cls");

            if (optionDisplay == 1) eqp1.printList();
            else if (optionDisplay == 2) cnm1.printList();
            break;

        case 2: // Add new equipment or consumable
            cout << "\033[32madd item\033[0m\n";
            cout << "1:equipment\n2:consumable\n";
            cin >> optionAdd;
            system("cls");

            if (optionAdd == 1) eqp1.AddToFront();
            else if (optionAdd == 2) cnm1.AddToFront();
            break;

        case 3: // Delete the first equipment item (stack-style removal)
            eqp1.DeleteFront();
            break;

        case 4: // Sort items by ID (ascending or descending)
            cout << "\033[32msort item\033[0m\n";
            cout << "1:equipment\n2:consumable\n";
            cin >> optionSort;
            system("cls");
            if (optionSort > 2) break;

            cout << "1. Ascending\n2. Descending\n";
            cin >> asc;
            system("cls");
            if (asc > 2) break;

            if (optionSort == 1) {          // Equipment sorting
                eqp1.sortID(asc == 1);
                eqp1.printList();
            }
            else if (optionSort == 2) {     // Consumable sorting
                cnm1.sortID(asc == 1);
                cnm1.printList();
            }
            break;

        case 5: { // Search item using Sentinel or Binary search
            int targetID, location;
            cout << "\033[32msearch item\033[0m\n";
            cout << "1. equipment\n2. consumable\n";
            cin >> optionSearch;
            system("cls");
            if (optionSearch > 2) break;

            cout << "\033[32mPick search method\033[0m:\n";
            cout << "1. Sentinel Search\n2. Binary Search\n";
            cin >> methodSearch;
            system("cls");
            if (methodSearch > 2) break;

            cout << "Enter ID to search: ";
            cin >> targetID;

            // Perform search based on selected list
            bool found = false;
            if (optionSearch == 1) {
                found = eqp1.SearchItem(targetID, location, methodSearch);
                if (found) {
                    cout << "\033[32mEquipment found at position: " << location << "\033[0m\n";
                    eqp1.printSingle();
                }
                else {
                    cout << "\033[31mEquipment not found\033[0m\n";
                }
            }
            else if (optionSearch == 2) {
                found = cnm1.SearchItem(targetID, location, methodSearch);
                if (found) {
                    cout << "\033[32mConsumable found at position: " << location << "\033[0m\n";
                    cnm1.printSingle();
                }
                else {
                    cout << "\033[31mConsumable not found\033[0m\n";
                }
            }
            break;
        }

        case 6: // Maintenance menu: display or add maintenance record
            cout << "\033[32mMaintenance\033[0m\n";
            cout << "1:display\n2:add\n";
            cin >> optionMnc;
            system("cls");
            if (optionMnc > 2) break;

            if (optionMnc == 1) mnc1.printList();
            else if (optionMnc == 2) mnc1.AddToFront();
            break;

        case 7: // Exit the program
        default:
            return 0;
        }

    } while (true);

    return 0;
}
