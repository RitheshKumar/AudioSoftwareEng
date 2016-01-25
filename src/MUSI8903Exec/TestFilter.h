#ifndef __MUSI8903__TestFilter__
#define __MUSI8903__TestFilter__

#include <iostream>
#include <fstream>
#include "FIRCombFilter.h"
#include "IIRCombFilter.h"
#include "AudioFileIf.h"

class TestFilter {
private:
    int _iWhichFilter;
    
    float _fDelayInSec;
    float _fGain;
    
    //suppose to use enum to deal with filter type selection
//    enum  _eFilterType {
//        FIRCombFilter = 0,
//        IIRCombFilter = 1
//    };
    
    float * _fTestSignal1;

    

    class FIRCombFilter *testFIR; 
    class IIRCombFilter *testIIR;

    
public:
    TestFilter(int filterType); //for naive test
    TestFilter(int filterType, float sampleRate, float delayInSec, float gain); //for test with audio file
    ~TestFilter();

    void initTestSignal();
    void zeroInputTest();
    void unitImpulseTest();
    void audioFileTest(float *audioFile, const int &fileLength);

    void fileWrite( float *writeVal, const char* fileName, const int &fileLength ) const;
    
    
};


#endif /* defined(__MUSI8903__TestFilter__) */
