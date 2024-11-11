/*
 *  PassengerQueue.h
 *  Armaan Sikka
 *  2/12/24
 *
 *  CS 15 HW 3 MetroSim - Time to get linked up in Fur
 *
 *  Class declarations for PassengerQueue class.
 *
 */

#ifndef __PASSENGER_QUEUE_H__
#define __PASSENGER_QUEUE_H__

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "Passenger.h"

class PassengerQueue {
public:
// nullary constructor and destructor
    PassengerQueue();
    ~PassengerQueue();

    Passenger front();
    void dequeue();
    void enqueue(const Passenger &passenger);
    int size();
    void print(std::ostream &output);

private:
// a vector to store the Passenger objects 'onboarded' by the program
    std::vector<Passenger> passengers;
};

#endif
