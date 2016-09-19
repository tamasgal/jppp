#include <string>
#include <vector>
#include "common.h"
#include "JLang/JObjectReader.hh"
#include "JDAQ/JDAQTimeslice.hh"
#include "JDAQTimesliceReader.h"

using namespace KM3NETDAQ ; // for JDAQTimeSlice
using namespace JSUPPORT;   // for JFileScanner
using namespace JLANG;  

namespace jppy {

    JSUPPORT::JFileScanner<KM3NETDAQ::JDAQTimeslice> fileScanner;
    KM3NETDAQ::JDAQTimeslice* timeslice;

    JDAQTimesliceReader::JDAQTimesliceReader() {}

    JDAQTimesliceReader::JDAQTimesliceReader(char* filename) {
        std::cout << "Filename in c++: " << filename << std::endl;
        fileScanner.open(filename);
    }

    void JDAQTimesliceReader::retrieveNextTimeslice() {
        timeslice = fileScanner.next();
    }
    bool JDAQTimesliceReader::hasNext() { return fileScanner.hasNext(); }

    void JDAQTimesliceReader::getHits() {
        int n_superframe = 0;
        int n_hit = 0;
        for( JDAQTimeslice::const_iterator superframe = timeslice->begin();
             superframe != timeslice->end();
             superframe++ ) {

            std::cout << "Superframe #" << n_superframe;
            for( JDAQSuperFrame::const_iterator hit=superframe->begin();
                 hit!=superframe->end();
                 ++hit ) {
                n_hit += 1;
                //std::cout << "    DOM: " << superframe->getModuleID();
                //std::cout << " , PMT: " << int(hit->getPMT());
                //std::cout << " , time: " << hit->getT();
                //std::cout << " , tot: " << int(hit->getToT()) << std::endl;
            }
            std::cout << " - " << n_hit << " hits" << std::endl;
            n_hit = 0;
            n_superframe += 1;
        }
    }
}