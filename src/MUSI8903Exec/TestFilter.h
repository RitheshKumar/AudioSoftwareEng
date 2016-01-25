#ifndef __MUSI8903__TestFilter__
#define __MUSI8903__TestFilter__

#include <iostream>
#include <fstream>
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
    float * _fTestSignal1; 

    int _iWhichFilter;

    class FIRCombFilter *testFIR; 
    class IIRCombFilter *testIIR;

    
public:
    TestFilter(int filterType);
    ~TestFilter();

    void initTestSignal();
    void zeroInputTest();
    void unitImpulseTest();

    void fileWrite( float *writeVal, const char* fileName ) const;
    
    
};


#endif /* defined(__MUSI8903__TestFilter__) */
