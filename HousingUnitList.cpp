#include "HousingUnitList.h"
#include <iostream>

void HousingUnitList::addUnit(const HousingUnit& unit) {
    units.push_back(unit);
}

bool HousingUnitList::editUnit(int unitNumber, const HousingUnit& updatedUnit) {
    for (auto& u : units) {
        if (u.getUnitNumber() == unitNumber) {
            u = updatedUnit;
            return true;
        }
    }
    return false;
}

bool HousingUnitList::deleteUnit(int unitNumber) {
    for (auto it = units.begin(); it != units.end(); ++it) {
        if (it->getUnitNumber() == unitNumber) {
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
    for (const auto& unit : units) {
        std::cout << unit << std::endl;
    }
}

// Operator overloads
HousingUnit& HousingUnitList::operator[](int index) {
    return units[index];
}

bool HousingUnitList::operator==(const HousingUnitList& other) const {
    return this->units == other.units;
}