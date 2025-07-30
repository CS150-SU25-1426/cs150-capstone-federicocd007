#include "HousingUnit.h"

HousingUnit::HousingUnit()
    : unitNumber(""), tenantName(""), isOccupied(false), monthlyRent(0.0) {}

HousingUnit::HousingUnit(std::string number, std::string tenant, bool occupied, double rent)
    : unitNumber(number), tenantName(tenant), isOccupied(occupied), monthlyRent(rent) {}

std::string HousingUnit::getUnitNumber() const { return unitNumber; }
std::string HousingUnit::getTenantName() const { return tenantName; }
bool HousingUnit::getIsOccupied() const { return isOccupied; }
double HousingUnit::getMonthlyRent() const { return monthlyRent; }

void HousingUnit::setUnitNumber(const std::string& num) { unitNumber = num; }
void HousingUnit::setTenantName(std::string tenant) { tenantName = tenant; }
void HousingUnit::setIsOccupied(bool occupied) { isOccupied = occupied; }
void HousingUnit::setMonthlyRent(double rent) { monthlyRent = rent; }

void HousingUnit::print(std::ostream& os) const {
    os << "Unit " << unitNumber << " | "
       << (isOccupied ? "Tenant: " + tenantName : "Vacant")
       << " | Rent: $" << monthlyRent;
}

bool HousingUnit::operator==(const HousingUnit& other) const {
    return unitNumber == other.unitNumber;
}

std::ostream& operator<<(std::ostream& os, const HousingUnit& unit) {
    unit.print(os);
    return os;
}