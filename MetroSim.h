/*
 *  MetroSim.h
 *  Armaan Sikka
 *  2/15/24
 *
 *  CS 15 HW 3 MetroSim - Time to get linked up in Fur
 *
 *  Functoin declarations for MetroSim Class.
 *
 */

#ifndef _METROSIM_H_
#define _METROSIM_H_

#include "Passenger.h"

// Put any other necessary includes here
#include "PassengerQueue.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

// Put any other structs you need here

class MetroSim {
public:
    MetroSim(string filename);
    ~MetroSim();
    void readStations(ifstream &input);
    void playSim(istream &input, ostream &output);
    void printCurr();
    void addPassenger(istream &input);
    void moveTrain(ostream &output);

private:
    vector<PassengerQueue> train;
    vector<PassengerQueue> passAtSt;
    vector<string> stationNames;
    int idNumCount;
    int totalNumSts;
    int dondeEsta;
};

#endif
