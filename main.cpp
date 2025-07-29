#include <iostream>
#include "HousingUnit.h"

int main() {
    HousingUnit unit1(101, "John Doe", true, 950.0);
    HousingUnit unit2(102, "", false, 950.0); // vacant
    HousingUnit unit3(101, "John Doe", true, 950.0);

    std::cout << unit1 << std::endl;
    std::cout << unit2 << std::endl;

    if (unit1 == unit3)
        std::cout << "unit1 and unit3 refer to the same apartment.\n";
    else
        std::cout << "unit1 and unit3 are different apartments.\n";

    return 0;
}