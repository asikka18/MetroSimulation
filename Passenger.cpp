/*
 *  Passenger.cpp
 *  Armaan Sikka
 *  2/12/24
 *
 *  CS 15 HW 3 MetroSim - Time to get linked up in Fur
 *
 *  Function definitions for Passenger class.
 *
 */

#include <iostream>
#include <string>
#include "Passenger.h"

/* print
 *    Purpose: To print the ID and travel information of a passenger object.
 * Parameters: Ostream
 *    Returns: None
 */
void Passenger::print(std::ostream &output)
{
        output << "[" << id << ", " << from << "->" << to << "]";
        return;
}
