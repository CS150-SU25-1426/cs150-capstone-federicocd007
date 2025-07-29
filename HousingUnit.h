#ifndef HOUSINGUNIT_H
#define HOUSINGUNIT_H

#include <string>
#include <iostream>

class HousingUnit {
protected:
    int unitNumber;
    std::string tenantName;
    bool isOccupied;
    double monthlyRent;

public:
    // Constructors
    HousingUnit();
    HousingUnit(int number, std::string tenant, bool occupied, double rent);

    // Virtual destructor for proper cleanup of derived classes
    virtual ~HousingUnit() {}

    // Getters and Setters
    int getUnitNumber() const;
    std::string getTenantName() const;
    bool getIsOccupied() const;
    double getMonthlyRent() const;

    void setTenantName(std::string tenant);
    void setIsOccupied(bool occupied);
    void setMonthlyRent(double rent);

    // Virtual print function for polymorphism
    virtual void print(std::ostream& os) const;

    // Operator overloads
    virtual bool operator==(const HousingUnit& other) const;
    friend std::ostream& operator<<(std::ostream& os, const HousingUnit& unit);
};

#endif