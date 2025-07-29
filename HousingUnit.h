#ifndef HOUSINGUNIT_H
#define HOUSINGUNIT_H

#include <string>
#include <iostream>

class HousingUnit {
private:
    int unitNumber;
    std::string tenantName;
    bool isOccupied;
    double monthlyRent;

public:
    // Constructors
    HousingUnit();
    HousingUnit(int number, std::string tenant, bool occupied, double rent);

    // Getters
    int getUnitNumber() const;
    std::string getTenantName() const;
    bool getIsOccupied() const;
    double getMonthlyRent() const;

    // Setters
    void setTenantName(std::string tenant);
    void setIsOccupied(bool occupied);
    void setMonthlyRent(double rent);

    // Operator Overloads
    bool operator==(const HousingUnit& other) const;
    friend std::ostream& operator<<(std::ostream& os, const HousingUnit& unit);
};

#endif