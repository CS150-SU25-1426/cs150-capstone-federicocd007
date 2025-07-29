#include <iostream>
#include "HousingUnit.h"
#include "HousingUnitList.h"

void showMenu() {
    std::cout << "\n--- Wesley House Manager ---\n";
    std::cout << "1. Add Unit\n";
    std::cout << "2. Edit Unit\n";
    std::cout << "3. Delete Unit\n";
    std::cout << "4. Show All Units\n";
    std::cout << "5. Exit\n";
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
            HousingUnit newUnit = createUnit();
            manager.addUnit(newUnit);
            break;
        }
        case 2: {
            int unitNum;
            std::cout << "Enter unit number to edit: ";
            std::cin >> unitNum;
            std::cin.ignore();
            HousingUnit updatedUnit = createUnit();
            if (!manager.editUnit(unitNum, updatedUnit))
                std::cout << "Unit not found.\n";
            break;
        }
        case 3: {
            int unitNum;
            std::cout << "Enter unit number to delete: ";
            std::cin >> unitNum;
            if (!manager.deleteUnit(unitNum))
                std::cout << "Unit not found.\n";
            break;
        }
        case 4:
            manager.showAllUnits();
            break;
        case 5:
            std::cout << "Goodbye!\n";
            break;
        default:
            std::cout << "Invalid option.\n";
        }

    } while (choice != 5);

    return 0;
}