#include "MaintenanceUnit.h"

MaintenanceUnit::MaintenanceUnit()
    : HousingUnit(), maintenanceIssue("Unknown") {
    isOccupied = false;
    tenantName = "N/A";
}

MaintenanceUnit::MaintenanceUnit(std::string unitNumber, std::string issue, double rent)
    : HousingUnit(unitNumber, "N/A", false, rent), maintenanceIssue(issue) {}

void MaintenanceUnit::setMaintenanceIssue(const std::string& issue) {
    maintenanceIssue = issue;
}

std::string MaintenanceUnit::getMaintenanceIssue() const {
    return maintenanceIssue;
}

void MaintenanceUnit::print(std::ostream& os) const {
    os << "Maintenance Unit " << unitNumber
       << " | Rent: $" << monthlyRent
       << " | Issue: " << maintenanceIssue;
}