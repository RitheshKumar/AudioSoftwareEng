#include "TestFilter.h"



TestFilter::TestFilter(int filterType): _iWhichFilter( filterType ), _fDelayInSec(0.3f), _fGain(0.8f), _fTestSignal1( new float[100] ) {
    
    if (filterType == 0) {
        //This is testing FIR
        testFIR = new class FIRCombFilter( _fDelayInSec, 100, _fGain );
    } else if ( filterType == 1) {
        //This is testing IIR
        testIIR = new class IIRCombFilter( _fDelayInSec, 100, _fGain );
    } else {
        std::cout << "No such filter" << std::endl;
    }

}

TestFilter::TestFilter(int filterType, float sampleRate, float delayInSec, float gain) {
    _iWhichFilter = filterType;
    if (filterType == 0) {
        // Test with FIR
        testFIR = new class FIRCombFilter(delayInSec, sampleRate, gain);
    } else if (filterType == 1) {
        // Test with IIR
        testIIR = new class IIRCombFilter(delayInSec, sampleRate, gain);
    } else {
        std::cout << "No such filter" << std::endl;
    }
}

TestFilter::~TestFilter() {
    delete _fTestSignal1;
    _fTestSignal1 = NULL;
}

// This is called by zeroInputTest and unitImpulseTest
void TestFilter::initTestSignal() {
    //Initialize testSignal to zeros
    for( int i = 0; i<100; i++ ) {
        _fTestSignal1[i] = 0.0;
    }
}

// This is called by testee1 and testee2 in Simple.cpp
void TestFilter::zeroInputTest() {

    initTestSignal();

    if( !_iWhichFilter ) {
        testFIR->filterProcess( _fTestSignal1, 100 );
    }
    else {
        testIIR->filterProcess( _fTestSignal1, 100 );
    }
        
    fileWrite( _fTestSignal1, "ZeroInputTest.txt", 100 );
}

// This is called by testee1 and testee2 in Simple.cpp
void TestFilter::unitImpulseTest() {

    initTestSignal();

    //unit impulse
    _fTestSignal1[0] = 1.0f;

    if( !_iWhichFilter ) {
        testFIR->filterProcess( _fTestSignal1, 100 );
    }
    else {
        testIIR->filterProcess( _fTestSignal1, 100 );
    }

    fileWrite( _fTestSignal1, "UnitImpulseFilter.txt", 100 );
}

// This is called by tester in Simple.cpp
void TestFilter::audioFileTest(float *audioFile, const int &fileLength) {
    if (!_iWhichFilter) {
        testFIR -> filterProcess(audioFile, fileLength);
        fileWrite(audioFile, "FIRAudioFileTestResult.txt", fileLength);
    } else {
        testIIR -> filterProcess(audioFile, fileLength);
        fileWrite(audioFile, "IIRAudioFileTestResult.txt", fileLength);
    }
}
    
void TestFilter::fileWrite( float *writeVal, const char* fileName, const int &fileLength ) const {

    std::ofstream outFile( fileName );
    std::ostream_iterator<float> outStream( outFile, "\n" );
    std::copy(writeVal, writeVal+fileLength, outStream);
    
}


