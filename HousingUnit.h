#ifndef HOUSINGUNIT_H
#define HOUSINGUNIT_H

#include <string>
#include <iostream>

class HousingUnit {
protected:
    std::string unitNumber;
    std::string tenantName;
    bool isOccupied;
    double monthlyRent;

public:
    HousingUnit();
    HousingUnit(std::string number, std::string tenant, bool occupied, double rent);
    virtual ~HousingUnit() {}

    std::string getUnitNumber() const;
    std::string getTenantName() const;
    bool getIsOccupied() const;
    double getMonthlyRent() const;

    void setUnitNumber(const std::string& num);
    void setTenantName(std::string tenant);
    void setIsOccupied(bool occupied);
    void setMonthlyRent(double rent);

    virtual void print(std::ostream& os) const;
    virtual bool operator==(const HousingUnit& other) const;
    friend std::ostream& operator<<(std::ostream& os, const HousingUnit& unit);
};

#endif