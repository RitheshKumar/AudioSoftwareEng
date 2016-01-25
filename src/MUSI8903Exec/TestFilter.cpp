#include "TestFilter.h"

TestFilter::TestFilter(int filterType): _iWhichFilter( filterType ), _fDelayInSec(0.3f), _fGain(0.8f), _fTestSignal1( new float[100] ) {
    
    if (filterType == 0) {
        //This is testing FIR
        testFIR = new class FIRCombFilter(_fTestSignal1, 100, _fDelayInSec, 100, _fGain);
    } else if ( filterType == 1) {
        //This is testing IIR
        testIIR = new class IIRCombFilter(_fTestSignal1, 100, _fDelayInSec, 100, _fGain);
    } else {
        std::cout << "No such filter" << std::endl;
    }

}

TestFilter::~TestFilter() {
    delete _fTestSignal1;
    _fTestSignal1 = NULL;
}

void TestFilter::initTestSignal() {
    //Initialize testSignal to zeros
    for( int i = 0; i<100; i++ ) {
        _fTestSignal1[i] = 0.0;
    }
}

void TestFilter::zeroInputTest() {

    initTestSignal();

    if( !_iWhichFilter ) {
        testFIR->filterProcess( _fTestSignal1, 100 );
    }
    else {
        testIIR->filterProcess( _fTestSignal1, 100 );
    }
        
    fileWrite( _fTestSignal1, "ZeroInputTest.txt" );
}

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

    fileWrite( _fTestSignal1, "UnitImpulseFilter.txt" );
}
    
void TestFilter::fileWrite( float *writeVal, const char* fileName ) const {

    std::ofstream outFile( fileName );
    std::ostream_iterator<float> outStream( outFile, "\n" );
    std::copy(writeVal, writeVal+100, outStream); //Don't understand why the end pointer is not beginPtr+fileLen-1 but beginPtr+fileLen

}


