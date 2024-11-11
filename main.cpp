/*
 *  main.cpp
 *  Armaan Sikka
 *  2/15/24
 *
 *  CS 15 HW 3 MetroSim - Time to get linked up in Fur
 *
 *  Main function that controls the simulation.
 *
 */

#include <iostream>
#include <fstream>
#include <string>

#include "MetroSim.h"

using namespace std;

void inputOpenOrDie(ifstream &input, string filename);
void outputOpenOrDie(ofstream &output, string filename);

int main(int argc, char *argv[]) {
    
    if (argc < 3 or argc > 4) {
        cerr << "Usage: ./MetroSim stationsFile outputFile [commandsFile]";
        exit(EXIT_FAILURE);

    } else if (argc == 3) {
        MetroSim sim(argv[1]);
        ofstream output;
        outputOpenOrDie(output, argv[2]);
        sim.playSim(cin, output);

    } else if (argc == 4) {
        MetroSim sim(argv[1]);
        ifstream input;
        ofstream output;
        outputOpenOrDie(output, argv[2]);
        inputOpenOrDie(input, argv[3]);

        sim.playSim(input, output);
    }

    return 0;
}

/*
 * name: inputOpenOrDie
 * purpose: To open the file given in the command line and check whether file is
 *          open
 * arguments: the input-file stream and the filename
 * returns: None
 * effects: exits program if file is not open
*/
void inputOpenOrDie(ifstream &input, string filename) {
    input.open(filename);

    if (not input.is_open()) {
        cerr << "Error: could not open file " << filename << endl;
        exit(EXIT_FAILURE);
    }
}

/*
 * name: outputOpenOrDie
 * purpose: To open the file given in the command line and check whether file is
 *          open
 * arguments: the output-file stream and the filename
 * returns: None
 * effects: exits program if file is not open
*/
void outputOpenOrDie(ofstream &output, string filename) {
    output.open(filename);

    if (not output.is_open()) {
        cerr << "Error: could not open file " << filename << endl;
        exit(EXIT_FAILURE);
    }
}
