// This is a short test script for your barrel.
// You should not need to change this file.
// You may use this to test your code, but passing these tests does *not* guarantee your code is correct.

#include <iostream>
#include "barrel.h"

void test_barrel()
{
    data_structures_assignment_1::barrel barrel1;
    data_structures_assignment_1::barrel barrel2;

    barrel1.add_water(60);
    barrel1.add_olive_oil(60);
    double barrel1_olive_oil_liters = barrel1.get_olive_oil_liters();
    if (barrel1_olive_oil_liters != 40)
    {
        std::cout << "Problem 1: Expected 40 olive oil quantity, but found " << barrel1_olive_oil_liters << std::endl;
        return;
    }
    barrel1.drain(35);
    double barrel1_water_liters = barrel1.get_water_liters();
    if (barrel1_water_liters != 25)
    {
        std::cout << "Problem 2: Expected 25 water quantity, but found " << barrel1_water_liters << std::endl;
        return;
    }
    double barrel1_empty_space = barrel1.get_empty_space();
    if (barrel1_empty_space != 35)
    {
        std::cout << "Problem 3: Expected 35 empty space, but found " << barrel1_empty_space << std::endl;
        return;
    }
    if (barrel1 == barrel2)
    {
        std::cout << "Problem 4: Barrel 1 was found to equal barrel 2, but they should have different liquids"
                  << std::endl;
        return;
    }
    barrel2.add_water(25);
    barrel2.add_olive_oil(40);
    if (!(barrel1 == barrel2))
    {
        std::cout << "Problem 5: Barrel 1 was not found to match barrel 2 when it should" << std::endl;
        return;
    }
    data_structures_assignment_1::barrel combined_barrel = barrel1 + barrel2;
    if (combined_barrel.get_empty_space() != 70 || combined_barrel.get_water_liters() != 50)
    {
        std::cout << "Problem 6: Combining barrel 1 and 2 seems to have produced a barrel with the wrong quantities"
                  << std::endl;
        return;
    }
    combined_barrel.add_water(110);
    combined_barrel.drain(120);
    if (combined_barrel.get_water_liters() != 40 || combined_barrel.get_olive_oil_liters() != 40)
    {
        std::cout << "Problem 7: Draining and/or adding water in the larger barrel has produced the wrong values."
                  << std::endl;
        return;
    }
    std::cout << "Test script passed without problems" << std::endl;
}

void test_barrel_assert1()
{
    data_structures_assignment_1::barrel barrel1(2.5, 200, 200);
}

void test_barrel_assert2()
{
    data_structures_assignment_1::barrel barrel1;
    barrel1.add_water(-1);
}

void test_barrel_assert3()
{
    data_structures_assignment_1::barrel barrel1;
    barrel1.add_olive_oil(-1);
}

void test_barrel_assert4()
{
    data_structures_assignment_1::barrel barrel1;
    barrel1.drain(-1);
}