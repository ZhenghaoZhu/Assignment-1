#include <cassert>
#include "barrel.h"

namespace data_structures_assignment_1
{
        barrel::barrel(){
            height = 1.0;
            water_liters = 0.0;
            olive_oil_liters = 0.0;
        }
        barrel::barrel(double init_height, double init_water_liters, double init_olive_oil_liters){
            assert((init_height*100.0) > (init_water_liters + init_olive_oil_liters)); // Checks if specified amounts fit the barrel
            height = init_height;
            water_liters = init_water_liters;
            olive_oil_liters = init_olive_oil_liters;
        }
        void barrel::add_water(double liters){
            assert(liters > 0.0); // Checks if positive
            water_liters += liters;
            overflowing(liters); // Extra amount overflows
        }
        void barrel::add_olive_oil(double liters){
            assert(liters > 0.0); // Checks if positive
            olive_oil_liters += liters;
            overflowing(liters); // Extra amount overflows
        }
        void barrel::overflowing(double liters){
            double total_liters = get_olive_oil_liters() + get_water_liters();
            if(total_liters > get_total_capacity()){ // Checks if the barrel is overfilled
                int excess = total_liters - get_total_capacity(); // How much is it overfilled by
                if(excess < get_olive_oil_liters()){ // Olive oil is drained first
                    olive_oil_liters -= excess;
                    return;
                }
                else{
                    excess -= get_olive_oil_liters(); // Subtracts olive oil first
                    olive_oil_liters = 0; // Drains out all olive oil
                    water_liters -= excess; // Subtracts remaining 
                    return;
                }
            }
            return;
        }
        void barrel::drain(double liters){
            assert(liters > 0.0);
            double total = get_water_liters() + get_olive_oil_liters();
            if(liters >= total){ // If draining amount is more than water and olive oil amount, empty everything
                water_liters = 0; // Drains all water
                olive_oil_liters = 0; // Drains all olive oil
                return;
            }
            if(get_water_liters() > liters){ // Draining amount is lesser than the water amount then just drain water
                water_liters -= liters; // Subtracts only water
                return;
            }
            else{ // Checking if the amount needed to be drained is greater than the amount of water
                liters -= get_water_liters(); // Subtracting water liters from total drain liters
                water_liters = 0; // Draining all of the water
                olive_oil_liters -= liters; // Draining remaining amount
                return;
            }
        }
        double barrel::get_water_liters() const{
            return water_liters;
        }
        double barrel::get_olive_oil_liters() const{
            return olive_oil_liters;
        }
        double barrel::get_height() const{
            return height;
        }
        double barrel::get_empty_space() const{
            double total_liters = get_olive_oil_liters() + get_water_liters(); // Used space
            return (get_total_capacity() - water_and_oil_liters); // Subtracting used space from total space
        }
        double barrel::get_total_capacity(){
            double total_capacity = get_height()*100.0; // Ratio of 1-100 as described in the notes
            return total_capacity;
        }
        bool operator==(const barrel &s1, const barrel &s2){
            return (s1.get_height() == s2.get_height()) && // Compares height
            (s1.get_olive_liters() == s2.get_olive_liters()) && // Compares amount of olive oil
            (s1.get_water_liters() == s2.get_water_liters()); // Compares amount of water
        }
        barrel operator+(const barrel &s1, const &s2){
            return barrel(s1.get_height() + s2.get_height(), // Adds heights
            s1.get_water_liters() + s2.get_water_liters(), // Adds water amounts
            s1.get_olive_oil_liters() + s2.get_olive_oil_liters()); // Adds olive oil amounts
        }

    }
}
