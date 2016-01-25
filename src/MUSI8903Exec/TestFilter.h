
#ifndef __MUSI8903__TestFilter__
#define __MUSI8903__TestFilter__

#include <stdio.h>
#include "FIRCombFilter.h"
#include "IIRCombFilter.h"

class TestFilter {
private:
    float _fDelayInSec;
    float _fGain;
    enum  _eFilterType {
        FIRCombFilter = 0,
        IIRCombFilter = 1
    };
    float * _fTestSignal1 = new float[100];

    FIRCombFilter *testeeFIR;
    IIRCombFilter *testeeIIR;
    
public:
    TestFilter(int filterType);
    
    
};


#endif /* defined(__MUSI8903__TestFilter__) */
