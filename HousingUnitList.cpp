#include "HousingUnitList.h"
#include "MaintenanceUnit.h"
#include <iostream>
#include <iomanip>

HousingUnitList::~HousingUnitList() {
    for (auto u : units) {
        delete u;
    }
}

void HousingUnitList::addUnit(HousingUnit* unit) {
    units.push_back(unit);
}

bool HousingUnitList::editUnit(const std::string& unitNumber, HousingUnit* updatedUnit) {
    for (size_t i = 0; i < units.size(); ++i) {
        if (units[i]->getUnitNumber() == unitNumber) {
            delete units[i];
            units[i] = updatedUnit;
            return true;
        }
    }
    return false;
}

bool HousingUnitList::deleteUnit(const std::string& unitNumber) {
    for (auto it = units.begin(); it != units.end(); ++it) {
        if ((*it)->getUnitNumber() == unitNumber) {
            delete *it;
            units.erase(it);
            return true;
        }
    }
    return false;
}

void HousingUnitList::showAllUnits() const {
    if (units.empty()) {
        std::cout << "No units available.\n";
        return;
    }

    std::cout << "\n--- Regular Housing Units ---\n";
    std::cout << std::left << std::setw(10) << "Unit"
              << std::setw(20) << "Tenant"
              << std::setw(10) << "Rent"
              << std::setw(10) << "Status" << "\n";
    std::cout << "---------------------------------------------\n";

    for (const auto& unit : units) {
        if (dynamic_cast<MaintenanceUnit*>(unit)) continue;

        std::cout << std::left
                  << std::setw(10) << unit->getUnitNumber()
                  << std::setw(20) << (unit->getIsOccupied() ? unit->getTenantName() : "Vacant")
                  << std::setw(10) << unit->getMonthlyRent()
                  << std::setw(10) << (unit->getIsOccupied() ? "Occupied" : "Empty")
                  << "\n";
    }

    std::cout << "\n--- Maintenance Units ---\n";
    std::cout << std::left << std::setw(10) << "Unit"
              << std::setw(20) << "Issue"
              << std::setw(10) << "Rent"
              << std::setw(10) << "Status" << "\n";
    std::cout << "---------------------------------------------\n";

    for (const auto& unit : units) {
        MaintenanceUnit* mUnit = dynamic_cast<MaintenanceUnit*>(unit);
        if (!mUnit) continue;

        std::cout << std::left
                  << std::setw(10) << mUnit->getUnitNumber()
                  << std::setw(20) << mUnit->getMaintenanceIssue()
                  << std::setw(10) << mUnit->getMonthlyRent()
                  << std::setw(10) << "Pending"
                  << "\n";
    }
}

HousingUnit* HousingUnitList::operator[](int index) {
    return units[index];
}

bool HousingUnitList::operator==(const HousingUnitList& other) const {
    if (units.size() != other.units.size()) return false;
    for (size_t i = 0; i < units.size(); ++i) {
        if (!(*units[i] == *other.units[i])) return false;
    }
    return true;
}
