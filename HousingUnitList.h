#ifndef HOUSINGUNITLIST_H
#define HOUSINGUNITLIST_H

#include <vector>
#include "HousingUnit.h"

class HousingUnitList {
private:
    std::vector<HousingUnit*> units;

public:
    ~HousingUnitList();  // To delete pointers

    void addUnit(HousingUnit* unit);
    bool editUnit(int unitNumber, HousingUnit* updatedUnit);
    bool deleteUnit(int unitNumber);
    void showAllUnits() const;

    HousingUnit* operator[](int index);
    bool operator==(const HousingUnitList& other) const;
};

#endif