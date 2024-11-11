/*
 *  MetroSim.h
 *  Armaan Sikka
 *  2/15/24
 *
 *  CS 15 HW 3 MetroSim - Time to get linked up in Fur
 *
 *  Functoin definitions for MetroSim Class.
 *
 */

#include "MetroSim.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

// Constructor that calls the readStations function to read in the stations
// file and populate the stationNames vector with the names of the stations
MetroSim::MetroSim(string filename) {
    ifstream instream;
    instream.open(filename);

    if (not instream.is_open()) {
        cerr << "Error: could not open file " << filename;
        exit(EXIT_FAILURE);
    }

    totalNumSts = 0;
    readStations(instream);
    instream.close();
    dondeEsta = 0;
    idNumCount = 1;
}

// Nullary Destructor
MetroSim::~MetroSim() {

}

/*
 * name: readStations
 * purpose: To open the file given in the comman line and read in the stations
 * arguments: the input-file stream and the filename
 * returns: None
 * effects: Adds a passengerQueue object for each station read in from the file
*/
void MetroSim::readStations(ifstream &input) {
//  While loop runs while the file is open and not at the end of the file. It
//  reads in the name of each station and adds it to a vector of strings
//  containing the names of all the stations in the stations file. It also
//  simultaneously creates passengerQueue classes within the train vector for
//  each station it reads in. A total numStations variable is incremented
    string name;
    while (getline(input, name)) {
        stationNames.push_back(name);
        PassengerQueue temp;
        train.push_back(temp);
        passAtSt.push_back(temp);
        totalNumSts++;
    }
}

/*
 * name: printCurr
 * purpose: To print the current state of the train 
 * arguments: none
 * returns: none
 * effects: none
*/
void MetroSim::printCurr() {
    /*
     *  Prints all the passengers on the train at the time the state of the
     *  train is printed.
    */
    cout << "Passengers on the train: {";
    for (int i = 0; i < totalNumSts; i++) {
        train.at(i).print(cout);
    }
    cout << "}\n";

    /*
     *  Prints the location of the train at the time the state of the train is
     *  printed and all the passengers waiting at any of the stations.
    */
    for (int i = 0; i < totalNumSts; i ++) {
        if (dondeEsta == i) {
            cout << "TRAIN: [" << i << "] " << stationNames[i];
            cout << " {";

            if (passAtSt.size() != 0) {
                if (passAtSt.at(i).size() != 0) {
                    passAtSt.at(i).print(cout);
                }
            }
            cout << "}\n";
            
        } else {
            cout << "       [" << i << "] " << stationNames[i];
            cout << " {";

            if (passAtSt.size() != 0) {
                if (passAtSt.at(i).size() != 0) {
                    passAtSt.at(i).print(cout);
                }
            }
            cout << "}\n";
        }
    }
}

/*
 * name: playSim
 * purpose: To run a query loop which executes the proper function on the train
 * arguments: the input stream and output stream
 * returns: none
 * effects: Calls separate functions depending on the query
*/
void MetroSim::playSim(istream &input, ostream &output) {
    string query = "m";
    bool continueLoop = true;

    while ((query == "m" or query == "p") and continueLoop and 
                                                            (not input.eof())) {
        printCurr();
        cout << "Command? ";
        input >> query;
        
        if (query == "m") {
            input >> query;
            if (query == "f") {
                continueLoop = false;

            } else if (query == "m") {
                moveTrain(output);
            }

        } else if (query == "p") {
            addPassenger(input);

        }
    }

    cout << "Thanks for playing MetroSim. Have a nice day!\n";
}

/*
 * name: moveTrain
 * purpose: To execute all the things that should occur before and after the 
 *          move train command is entered
 * arguments: the output stream
 * returns: None
 * effects: Onboards passengers at the current station, moves the train to the
 *          next station and then offboards the passengers set to depart at the
 *          station just arrived at
*/
void MetroSim::moveTrain(ostream &output) {
    /*
     *  Onboards passengers waiting at the current station in their respective
     *  departure-station car.
     */
    if (passAtSt.at(dondeEsta).size() != 0) {
        while (passAtSt.at(dondeEsta).size() != 0) {
            Passenger temp1 = passAtSt.at(dondeEsta).front();
            passAtSt.at(dondeEsta).dequeue();
            train.at(temp1.to).enqueue(temp1);
        }
    }

    /*
     *  Checks whether current station is the last station and moves to the
     *  first station if it is and the next station if it is not.
     */
    if (dondeEsta == (totalNumSts - 1)) {
        dondeEsta = 0;

    } else {
        dondeEsta++;
    }

    /*
     *  Offboards the passengers in the train car containing the passengers
     *  meant to depart at the current staion.
     */
    if (train.at(dondeEsta).size() != 0) {
        while (train.at(dondeEsta).size() != 0) {
            Passenger temp2 = train.at(dondeEsta).front();
            output << "Passenger " << temp2.id << " left train at station ";
            output << stationNames[dondeEsta] << "\n";
            train.at(dondeEsta).dequeue();
        }
    }
        
}

/*
 * name: addPassenger
 * purpose: To add a new passenger specified through the input stream to the
 *          back of the queue of the passengers at the current station
 * arguments: the input stream
 * returns: None
 * effects: Adds a Passenger object to the back of the queue at the current
 *          station
*/
void MetroSim::addPassenger(istream &input) {
    int from, to;
    input >> from >> to;

    Passenger temp3(idNumCount, from, to);
    passAtSt.at(from).enqueue(temp3);
    idNumCount++;
}
