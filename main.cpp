#include <iostream>
#include "HousingUnit.h"
#include "HousingUnitList.h"
#include "MaintenanceUnit.h"

using namespace std;

void showMenu() {
    cout << "***Wesley House Manager***\n\n";
    cout << "1. Add Unit\n";
    cout << "2. Edit Unit\n";
    cout << "3. Delete Unit\n";
    cout << "4. Show All Units\n";
    cout << "5. Exit\n\n";
    cout << "Select an option: ";
}

HousingUnit createUnit() {
    int unitNum;
    string tenant;
    bool occupied;
    double rent;

    cout << "Enter unit number: ";
    cin >> unitNum;
    cin.ignore();

    cout << "Enter tenant name (or leave blank if vacant): ";
    getline(cin, tenant);
    occupied = !tenant.empty();

    cout << "Enter monthly rent: ";
    cin >> rent;

    return HousingUnit(unitNum, tenant, occupied, rent);
}

int main() {
    HousingUnitList manager;
    int choice;

    do {
        showMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            int typeChoice;
            cout << "\n1. Add Regular Unit\n2. Add Maintenance Unit\n";
            cin >> typeChoice;
            cin.ignore();

            if (typeChoice == 1) {
                HousingUnit* unit = new HousingUnit(createUnit());
                manager.addUnit(unit);
            } else if (typeChoice == 2) {
                int unitNum;
                string issue;
                double rent;

            cout << "Enter unit number: ";
            cin >> unitNum;
            cin.ignore();

            cout << "Enter maintenance issue: ";
            getline(cin, issue);
   
            cout << "Enter monthly rent: ";
            cin >> rent;

            HousingUnit* mu = new MaintenanceUnit(unitNum, issue, rent);
                manager.addUnit(mu);
            } else {
                cout << "Invalid type.\n";
            }
            break;
        }
        case 2: {
            int unitNum;
            cout << "\nEnter unit number to edit: ";
            cin >> unitNum;
            cin.ignore();

            int typeChoice;
            cout << "1. Edit Regular Unit\n2. Edit Maintenance Unit\n";
            cin >> typeChoice;
            cin.ignore();

            HousingUnit* updatedUnit = nullptr;

            if (typeChoice == 1) {
                updatedUnit = new HousingUnit(createUnit());
            } else if (typeChoice == 2) {
            string issue;
            double rent;

            cout << "Enter maintenance issue: ";
            getline(cin, issue);

            cout << "Enter monthly rent: ";
            cin >> rent;

            updatedUnit = new MaintenanceUnit(unitNum, issue, rent);
        }

            if (updatedUnit) {
                if (!manager.editUnit(unitNum, updatedUnit)) {
            cout << "Unit not found.\n";
            delete updatedUnit;  // prevent memory leak
            }
        }
        break;
        }
        case 3: {
            int unitNum;
            cout << "\nEnter unit number to delete: ";
            cin >> unitNum;
            if (!manager.deleteUnit(unitNum))
                cout << "Unit not found.\n";
            break;
        }
        case 4:
            cout << "\n";
            manager.showAllUnits();
            cout << "\n";
            break;
        case 5:
            cout << "\nGoodbye!\n\n";
            break;
        default:
            cout << "\nInvalid option.\n";
        }

    } while (choice != 5);

    return 0;
}