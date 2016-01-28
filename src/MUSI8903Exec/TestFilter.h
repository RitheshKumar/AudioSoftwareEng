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
    
    //suppose to use enum to deal with filter type selection
//    enum  _eFilterType {
//        FIRCombFilter = 0,
//        IIRCombFilter = 1
//    };
    
    float * _fTestSignal;
    

    class FIRCombFilter *testFIR; 
    class IIRCombFilter *testIIR;

    
public:
    TestFilter(int filterType,  float sampleRate=100, float delayInSec=0.3f, float gain=0.8f, const int &numChannels=1); //for test with audio file
    ~TestFilter();

    void initTestSignal();
    void zeroInputTest();
    void unitImpulseTest();
    void audioFileTest(float **audioFile, const int &fileLength, const int &numChannels=1);
    
    void fileWrite( float **writeVal, const char* fileName, const int &fileLength, const int &numChannels=1 ) const;
    void fileWrite( float *writeVal, const char* fileName, const int &fileLength, const int &numChannels=1 ) const;
    
    
};


#endif /* defined(__MUSI8903__TestFilter__) */
