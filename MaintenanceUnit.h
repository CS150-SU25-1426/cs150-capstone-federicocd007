#ifndef MAINTENANCEUNIT_H
#define MAINTENANCEUNIT_H

#include "HousingUnit.h"

class MaintenanceUnit : public HousingUnit {
private:
    std::string maintenanceIssue;

public:
    MaintenanceUnit();
    MaintenanceUnit(int unitNumber, std::string issue, double rent);
    ~MaintenanceUnit() override {}

    void setMaintenanceIssue(const std::string& issue);
    std::string getMaintenanceIssue() const;

    // Override print method
    void print(std::ostream& os) const override;
};

#endif