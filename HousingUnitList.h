#ifndef HOUSINGUNITLIST_H
#define HOUSINGUNITLIST_H

#include <vector>
#include "HousingUnit.h"

class HousingUnitList {
private:
    std::vector<HousingUnit> units;

public:
    void addUnit(const HousingUnit& unit);
    bool editUnit(int unitNumber, const HousingUnit& updatedUnit);
    bool deleteUnit(int unitNumber);
    void showAllUnits() const;

    // Operator overloads
    HousingUnit& operator[](int index);  // Access by index
    bool operator==(const HousingUnitList& other) const; // Compare lists
};

#endif