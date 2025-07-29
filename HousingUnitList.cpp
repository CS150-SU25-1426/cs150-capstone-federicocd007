#include "HousingUnitList.h"
#include <iostream>

HousingUnitList::~HousingUnitList() {
    for (auto u : units) {
        delete u;
    }
}

void HousingUnitList::addUnit(HousingUnit* unit) {
    units.push_back(unit);
}

bool HousingUnitList::editUnit(int unitNumber, HousingUnit* updatedUnit) {
    for (size_t i = 0; i < units.size(); ++i) {
        if (units[i]->getUnitNumber() == unitNumber) {
            delete units[i];
            units[i] = updatedUnit;
            return true;
        }
    }
    return false;
}

bool HousingUnitList::deleteUnit(int unitNumber) {
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
    for (const auto& unit : units) {
        std::cout << *unit << std::endl;
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