#include <iostream>
#include <iomanip>
#include <limits>
#include <sstream>
#include "HousingUnit.h"
#include "MaintenanceUnit.h"
#include "HousingUnitList.h"

// Helper input functions
std::string getString(const std::string& prompt) {
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);
    return input;
}

int getValidatedInt(const std::string& prompt) {
    std::string input;
    int value;

    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        std::stringstream ss(input);

        if ((ss >> value) && ss.eof()) {
            return value;
        }
        std::cout << "Invalid input. Please enter a valid whole number.\n";
    }
}

std::string getOptionalString(const std::string& prompt) {
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);

    // Trim leading/trailing spaces
    input.erase(0, input.find_first_not_of(" \t"));
    input.erase(input.find_last_not_of(" \t") + 1);

    return input;
}

double getValidatedDouble(const std::string& prompt) {
    std::string input;
    double value;

    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        std::stringstream ss(input);

        if ((ss >> value) && ss.eof()) {
            return value;
        }
        std::cout << "Invalid input. Please enter a valid number.\n";
    }
}

std::string getValidatedString(const std::string& prompt) {
    std::string input;

    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);

        // Trim leading/trailing whitespace
        input.erase(0, input.find_first_not_of(" \t"));
        input.erase(input.find_last_not_of(" \t") + 1);

        if (!input.empty()) {
            return input;
        }

        std::cout << "Invalid input. Please enter a non-empty string.\n";
    }
}

HousingUnit createUnit() {
    std::string unitNum = getString("Enter unit number (e.g. 112D): ");
    std::string tenant = getOptionalString("Enter tenant name: (leave blank if vacant): ");
    bool occupied = !tenant.empty();
    double rent = getValidatedDouble("Enter monthly rent: ");
    return HousingUnit(unitNum, tenant, occupied, rent);
}

int main() {
    HousingUnitList manager;
    int choice;

    do {
        std::cout << "*****************************************\n";
        std::cout << "**                                     **\n";
        std::cout << "**   Wesley House - Property Manager   **\n";
        std::cout << "**                                     **\n";
        std::cout << "*****************************************\n";
        std::cout << "1. Add Unit\n2. Edit Unit\n3. Delete Unit\n4. Show All Units\n0. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;
        std::cin.ignore(10000, '\n');

        switch (choice) {
        case 1: {
            std::cout << "1. Regular Unit\n2. Maintenance Unit\n";
            int type;
            std::cin >> type;
            std::cin.ignore(10000, '\n');

            if (type == 1) {
                HousingUnit* unit = new HousingUnit(createUnit());
                manager.addUnit(unit);
            } else if (type == 2) {
                std::string unitNum = getString("Enter unit number: ");
                std::string issue = getString("Enter maintenance issue: ");
                double rent = getValidatedDouble("Enter monthly rent: ");
                HousingUnit* unit = new MaintenanceUnit(unitNum, issue, rent);
                manager.addUnit(unit);
            }
            break;
        }
        case 2: {
            std::string unitNum = getString("Enter unit number to edit: ");
            std::cout << "1. Edit Regular\n2. Edit Maintenance\n";
            int type;
            std::cin >> type;
            std::cin.ignore(10000, '\n');

            HousingUnit* updated = nullptr;
            if (type == 1) {
                updated = new HousingUnit(createUnit());
            } else if (type == 2) {
                std::string issue = getString("Enter issue: ");
                double rent = getValidatedDouble("Enter rent: ");
                updated = new MaintenanceUnit(unitNum, issue, rent);
            }

            if (!manager.editUnit(unitNum, updated)) {
                std::cout << "Unit not found.\n";
                delete updated;
            }
            break;
        }
        case 3: {
            std::string unitNum = getString("Enter unit number to delete: ");
            if (!manager.deleteUnit(unitNum)) {
                std::cout << "Unit not found.\n";
            }
            break;
        }
        case 4:
            manager.showAllUnits();
            break;
        case 0:
            std::cout << "Have a great day!\n";
            break;
        default:
            std::cout << "Invalid option.\n";
        }

    } while (choice != 0);

    return 0;
}