// FILE: barrel.h
// CLASS PROVIDED: barrel
//   (a class to keep track of a barrel which can hold liquid)
//   This class is part of the namespace data_structures_assignment_1.
//
// CONSTRUCTOR for the barrel class:
//   barrel();
//     Postcondition: The object has been initialized as an empty barrel ready to hold liquid. The barrel has a
//                    height of 1 meter which can hold 100 liters.
//   barrel(double init_height, double init_water_liters, double init_olive_oil_liters);
//     Precondition: The specified water amount and olive oil amount must fit in a barrel of the specified height.
//                   For every 1 meter of height a barrel has it can hold 100 liters.
//     Postcondition: The object has been initialized as a barrel with the specified height (in meters),
//                    water amount (in liters), and olive oil amount (in liters).
//
// PUBLIC MODIFICATION member functions for the barrel class:
//   void add_water(double liters)
//     Precondition: `liters` cannot be negative.
//     Postcondition: Adds `liters` number of liters of water to the barrel. If the resulting liquid quantity is
//                    more than the barrel can hold, the barrel overflows. First excess olive oil is lost (because it
//                    floats on the water), and then excess water is lost until the barrel is no longer overflowing.
//   void add_olive_oil(double liters)
//     Precondition: `liters` cannot be negative.
//     Postcondition: Adds `liters` number of liters of olive oil to the barrel. If the resulting liquid quantity is
//                    more than the barrel can hold, the barrel overflows. First excess olive oil is lost (because it
//                    floats on the water), and then excess water is lost until the barrel is no longer overflowing.
//   void drain(double liters);
//     Precondition: `liters` cannot be negative.
//     Postcondition: Drains `liters` amount of liters of liquid from the barrel. The water drains before the olive
//                    does (because the oil floats on water and it is being drained from the bottom). If `liters`
//                    is greater than the amount of liquid in the barrel, the barrel becomes empty.
//
// PUBLIC CONSTANT member functions for the barrel class:
//   double get_water_liters() const
//     Postcondition: The return value is the amount of water currently in the barrel (in liters).
//   double get_olive_oil_liters() const
//     Postcondition: The return value is the amount of olive oil currently in the barrel (in liters).
//   double get_height() const
//     Postcondition: The return value is the height of the barrel (in meters).
//
// PRIVATE CONSTANT member functions for the barrel class:
//   double get_empty_space() const
//     Postcondition: The return value is the amount of empty space in the barrel (in liters).
//
// NON-MEMBER functions for the barrel class:
//   barrel operator +(const barrel& b1, const barrel& b2)
//     Postcondition: The two barrels are stacked. A new barrel is returned which has twice the height, and therefore
//                    twice the capacity. The new barrel has the combined liquid contents of the original two barrels.
//   bool operator ==(const barrel& b1, const barrel& b2)
//     Postcondition: The return value is true if `b1` and `b2` have the same height and the same liquid contents.
//
// VALUE SEMANTICS for the barrel class:
// Assignments and the copy constructor may be used with barrel objects.

#ifndef DATA_STRUCTURES_ASSIGNMENT_1_BARREL_H
#define DATA_STRUCTURES_ASSIGNMENT_1_BARREL_H

namespace data_structures_assignment_1
{
    class barrel
    {
    public:
        // CONSTRUCTOR
        barrel();
        barrel(double init_height, double init_water_liters, double init_olive_oil_liters);
        // MODIFICATION MEMBER FUNCTIONS
        void add_water(double liters);
        void add_olive_oil(double liters);
        void overflowing(double liters);
        void drain(double liters);
        // CONSTANT MEMBER FUNCTIONS
        double get_water_liters() const;
        double get_olive_oil_liters() const;
        double get_height() const;
        double get_empty_space() const;
        // FRIEND FUNCTIONS
        friend barrel operator+(const barrel &s1, const barrel &s2);

    private:
        double height;  // The height of the barrel (in meters)
        double water_liters;  // The amount of water in the barrel (in liters)
        double olive_oil_liters;  // The amount of water in the barrel (in liters)
        double get_total_capacity() const;  // Returns the total capacity of the barrel (in liters)
    };

    // NON-MEMBER functions for the barrel class
    bool operator==(const barrel &s1, const barrel &s2);
};

#endif // DATA_STRUCTURES_ASSIGNMENT_1_BARREL_H
