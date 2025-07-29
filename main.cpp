#include <iostream>
#include "HousingUnit.h"
#include "HousingUnitList.h"
#include "MaintenanceUnit.h"

void showMenu() {
    std::cout << "***Wesley House Manager***\n\n";
    std::cout << "1. Add Unit\n";
    std::cout << "2. Edit Unit\n";
    std::cout << "3. Delete Unit\n";
    std::cout << "4. Show All Units\n";
    std::cout << "5. Exit\n\n";
    std::cout << "Select an option: ";
}

HousingUnit createUnit() {
    int unitNum;
    std::string tenant;
    bool occupied;
    double rent;

    std::cout << "Enter unit number: ";
    std::cin >> unitNum;
    std::cin.ignore();

    std::cout << "Enter tenant name (or leave blank if vacant): ";
    std::getline(std::cin, tenant);
    occupied = !tenant.empty();

    std::cout << "Enter monthly rent: ";
    std::cin >> rent;

    return HousingUnit(unitNum, tenant, occupied, rent);
}

int main() {
    HousingUnitList manager;
    int choice;

    do {
        showMenu();
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
        case 1: {
            int typeChoice;
            std::cout << "\n1. Add Regular Unit\n2. Add Maintenance Unit\n";
            std::cin >> typeChoice;
            std::cin.ignore();

            if (typeChoice == 1) {
                HousingUnit* unit = new HousingUnit(createUnit());
                manager.addUnit(unit);
            } else if (typeChoice == 2) {
                int unitNum;
                std::string issue;
                double rent;

            std::cout << "Enter unit number: ";
            std::cin >> unitNum;
            std::cin.ignore();

            std::cout << "Enter maintenance issue: ";
            std::getline(std::cin, issue);
   
            std::cout << "Enter monthly rent: ";
            std::cin >> rent;

            HousingUnit* mu = new MaintenanceUnit(unitNum, issue, rent);
                manager.addUnit(mu);
            } else {
                std::cout << "Invalid type.\n";
            }
            break;
        }
        case 2: {
            int unitNum;
            std::cout << "\nEnter unit number to edit: ";
            std::cin >> unitNum;
            std::cin.ignore();

            int typeChoice;
            std::cout << "1. Edit Regular Unit\n2. Edit Maintenance Unit\n";
            std::cin >> typeChoice;
            std::cin.ignore();

            HousingUnit* updatedUnit = nullptr;

            if (typeChoice == 1) {
                updatedUnit = new HousingUnit(createUnit());
            } else if (typeChoice == 2) {
            std::string issue;
            double rent;

            std::cout << "Enter maintenance issue: ";
            std::getline(std::cin, issue);

            std::cout << "Enter monthly rent: ";
            std::cin >> rent;

            updatedUnit = new MaintenanceUnit(unitNum, issue, rent);
        }

            if (updatedUnit) {
                if (!manager.editUnit(unitNum, updatedUnit)) {
            std::cout << "Unit not found.\n";
            delete updatedUnit;  // prevent memory leak
            }
        }
        break;
        }
        case 3: {
            int unitNum;
            std::cout << "\nEnter unit number to delete: ";
            std::cin >> unitNum;
            if (!manager.deleteUnit(unitNum))
                std::cout << "Unit not found.\n";
            break;
        }
        case 4:
            manager.showAllUnits();
            break;
        case 5:
            std::cout << "\nGoodbye!\n\n";
            break;
        default:
            std::cout << "\nInvalid option.\n";
        }

    } while (choice != 5);

    return 0;
}