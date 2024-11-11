/*  unit_tests.h
 *  Armaan Sikka
 *  2/15/24
 *
 *  CS 15 HW 3 MetroSim - Time to get linked up in Fur
 *
 *  A testing file for the PassengerQueue class that uses the unit_test
 *  framework
 */

#include "PassengerQueue.h"
#include <cassert>
#include <iostream>

using namespace std;


void constructor_test() {
    PassengerQueue car;
}

void front_enqueue_and_print_test() {
    PassengerQueue car;

    Passenger dude1(1, 1, 2);
    Passenger dude2(2, 2, 3);

    car.enqueue(dude1);
    car.enqueue(dude2);

    cout << "should be [1, 1->2][2, 2->3]. It is: ";
    car.print(cout);
}

void dequeue_test() {
    PassengerQueue car;

    Passenger dude1(1, 1, 2);
    Passenger dude2(2, 2, 3);

    car.enqueue(dude1);
    car.enqueue(dude2);

    car.dequeue();

    cout << "should be [2, 2->3]. It is: ";
    car.print(cout);
}

void size_test() {
    PassengerQueue car;

    Passenger dude1(1, 1, 2);
    Passenger dude2(2, 2, 3);

    car.enqueue(dude1);
    car.enqueue(dude2);

    cout << "size should be 2. It is: ";
    cout << car.size() << endl;
}
