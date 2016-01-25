
#include "TestFilter.h"

TestFilter::TestFilter(int filterType): _fDelayInSec(0.3f), _fGain(0.8f) {
    if (filterType == 0) {
        //This is testing FIR
        testeeFIR = new  class FIRCombFilter(_fTestSignal1, 100, _fDelayInSec, 100, _fGain);
    } else if ( filterType == 1) {
        //This is testing IIR
        
    } else {
        std::cout << "No such filter" << std::endl;
    }
};