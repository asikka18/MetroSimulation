/*
 *  PassengerQueue.cpp
 *  Armaan Sikka
 *  2/12/24
 *
 *  CS 15 HW 3 MetroSim - Time to get linked up in Fur
 *
 *  Function definitions for PassengerQueue class.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include "PassengerQueue.h"

/*
 * nullary constructor
*/
PassengerQueue::PassengerQueue() {

}

/*
 * nullary destructor
*/
PassengerQueue::~PassengerQueue() {

}

/*
 * name: front
 * purpose: To return the first element of the queue
 * arguments: none
 * returns: The element at the front of the queue (Passenger-type)
 * effects: Function throws an exception if the function is called when the
 *          queue is empty so that the program does not crash.
*/
Passenger PassengerQueue::front() {
    if (passengers.empty()) {
        throw std::range_error("empty queue");
    }

    return passengers.front();
}

/*
 * name: dequeue
 * purpose: To remove the first passenger in the queue
 * arguments: none
 * returns: none
 * effects: Function throws an exception if the function is called when the
 *          queue is empty so that the program does not crash.
*/
void PassengerQueue::dequeue() {
    if (passengers.empty()) {
        throw std::range_error("cannot dequeue empty queue");
    }

    passengers.erase(passengers.begin());

    return;
}

/*
 * name: enqueue
 * purpose: To add the given element to the back of the queue
 * arguments: a Passenger object
 * returns: none
 * effects: adds the given element to the back of the queue
*/
void PassengerQueue::enqueue(const Passenger &passenger) {
    passengers.push_back(passenger);

    return;
}

/*
 * name: size
 * purpose: To return the size of the queue
 * arguments: none
 * returns: the integer value of the size
 * effects: none
*/
int PassengerQueue::size() {
    return passengers.size();
}

/*
 * name: print
 * purpose: To print the information of each Passenger object in the queue
 * arguments: an output stream
 * returns: none
 * effects: retrieves the information of each Passenger object in the queue
 *          through the print function in the Passenger class and outputs it
 *          into the output stream given
*/
void PassengerQueue::print(std::ostream &output) {
    for (unsigned long i = 0; i < passengers.size(); i++) {
        passengers[i].print(output);
    }

    return;
}
