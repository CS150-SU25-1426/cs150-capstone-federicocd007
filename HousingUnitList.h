#ifndef HOUSINGUNITLIST_H
#define HOUSINGUNITLIST_H

#include <vector>
#include "HousingUnit.h"

class HousingUnitList {
private:
    std::vector<HousingUnit*> units;

public:
    ~HousingUnitList();

    void addUnit(HousingUnit* unit);
    bool editUnit(const std::string& unitNumber, HousingUnit* updatedUnit);
    bool deleteUnit(const std::string& unitNumber);
    void showAllUnits() const;

    HousingUnit* operator[](int index);
    bool operator==(const HousingUnitList& other) const;
};

#endif