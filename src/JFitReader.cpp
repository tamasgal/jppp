#include "common.h"
/*
#include <iostream>
#include <map>
#include "JFitReader.h"
#include "JDAQ/JEvt.hh"
#include "JSupport/JMultipleFileScanner.hh"
*/


namespace jppy {

    JSUPPORT::JFileScanner<JFIT::JEvt> fileScanner;
    JFIT::JEvt* event;

    JFitReader::JFitReader() {}

    JFitReader::JFitReader(char* filename) {
        std::cout << "Filename in c++: " << filename << std::endl;
        fileScanner.open(filename);
    }

    void JFitReader::retrieveNextEvent() { event = fileScanner.next(); }
    bool JFitReader::hasNext() { return fileScanner.hasNext(); }

    double JFitReader::getNFits() { return event->size(); }

    void JFitReader::getFits(
        double* pos_xs,
        double* pos_ys,
        double* pos_zs,
        double* dir_xs,
        double* dir_ys,
        double* dir_zs,
        int* ndfs,
        double* times,
        double* qualities,
        double* energies,
        ){

        int nFits = event.size();

        for (int i = 0; i < nFits; i++) {
            double pos_x = (double)nFits[i].getX();
            double pos_y = (double)nFits[i].getY();
            double pos_z = (double)nFits[i].getZ();
            double dir_x = (double)nFits[i].getDX();
            double dir_y = (double)nFits[i].getDY();
            double dir_z = (double)nFits[i].getDZ();
            int ndf = (int)nFits[i].getNDF();
            double time = (double)nFits[i].getT();
            double quality = (double)nFits[i].getQ();
            double energy = (double)nFits[i].getE();
            pos_xs[i] = pos_x;
            pos_ys[i] = pos_y;
            pos_zs[i] = pos_z;
            dir_xs[i] = dir_x;
            dir_ys[i] = dir_y;
            dir_zs[i] = dir_z;
            times[i] = time;
            qualities[i] = quality;
            energies[i] = energy;
        }
    }
}
