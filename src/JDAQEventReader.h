#ifndef PKG_JPPY_SRC_JDAQEVENTREADER_H_
#define PKG_JPPY_SRC_JDAQEVENTREADER_H_

namespace jppy {
class JDAQEventReader {
    public:
        JDAQEventReader();
        JDAQEventReader(char* filename);
        void retrieveNextEvent();
        int getFrameIndex();
        int getRunNumber();
        int getDetectorID();
        int getTriggerCounter();
        int getTriggerMask();
        int getSize();
        unsigned int getOverlays();
        int getUTCSeconds();
        int getUTCNanoseconds();
        int getNumberOfSnapshotHits();
        void getHits(int* channel_ids, int* dom_ids, int* times, int* tots,
                     int* triggereds);
        bool hasNext();
    // private:
    //     JSUPPORT::JFileScanner<KM3NETDAQ::JDAQEvent> file_scanner;
    //     KM3NETDAQ::JDAQEvent* event;
};
}   // namespace jppy

#endif  // PKG_JPPY_SRC_JDAQEVENTREADER_H_
