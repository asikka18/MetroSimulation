/*
 *  Passenger.h
 *  Armaan Sikka
 *  2/12/24
 *
 *  CS 15 HW 3 MetroSim - Time to get linked up in Fur
 *
 *  Function declarations for Passenger class.
 *
 */

#ifndef __PASSENGER_H__
#define __PASSENGER_H__

#include <iostream>

struct Passenger
{

        int id, from, to;
        
        Passenger()
        {
                id   = -1;
                from = -1;
                to   = -1;
        }

        Passenger(int newId, int arrivalStation, int departureStation)
        {
                id   = newId;
                from = arrivalStation;
                to   = departureStation;
        }

        void print(std::ostream &output);

};

#endif
