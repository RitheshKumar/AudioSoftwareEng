#include "TestFilter.h"


TestFilter::TestFilter(int filterType, float sampleRate, float delayInSec, float gain ) : _iWhichFilter( filterType ), _fTestSignal( new float[100] ) {
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
    delete _fTestSignal;
    _fTestSignal = NULL;
}

void TestFilter::initTestSignal() {
    //Initialize testSignal to zeros
    for( int i = 0; i<100; i++ ) {
        _fTestSignal[i] = 0.0;
    }
}

void TestFilter::zeroInputTest() {

    initTestSignal();

    if( !_iWhichFilter ) {
        testFIR->filterProcess( _fTestSignal, 100 );
        fileWrite( _fTestSignal, "FIRZeroInputTest.txt", 100 );
    }
    else {
        testIIR->filterProcess( _fTestSignal, 100 );
        fileWrite( _fTestSignal, "IIRZeroInputTest.txt", 100 );
    }
        
    
}

void TestFilter::unitImpulseTest() {

    initTestSignal();

    //unit impulse
    _fTestSignal[0] = 1.0f;

    if( !_iWhichFilter ) {
        testFIR->filterProcess( _fTestSignal, 100 );
        fileWrite( _fTestSignal, "FIRUnitImpulseFilter.txt", 100 );
    }
    else {
        testIIR->filterProcess( _fTestSignal, 100 );
        fileWrite( _fTestSignal, "IIRUnitImpulseFilter.txt", 100 );
    }

    
}

void TestFilter::audioFileTest(float **audioFile, const int &fileLength, const int &numChannels) {
    if (!_iWhichFilter) {
        for ( int i=0; i<numChannels; i++ ) {
            testFIR -> filterProcess(audioFile[i], fileLength);
        }
        fileWrite(audioFile, "FIRAudioFileTestResult.txt", fileLength, numChannels);
    } else {
        for ( int i=0; i<numChannels; i++ ) {
            testIIR -> filterProcess(audioFile[i], fileLength);
        }
        fileWrite(audioFile, "IIRAudioFileTestResult.txt", fileLength, numChannels);
    }
}
    
void TestFilter::fileWrite( float **writeVal, const char* fileName, const int &fileLength, const int &numChannels ) const {

    std::ofstream outFile( fileName );
    //std::ostream_iterator<float> outStream( outFile, "\n" );
    for ( int i=0; i<fileLength; i++ ) {
        for ( int j=0; j<numChannels; j++ ) {
            outFile << writeVal[j][i] << "\t";
        }
        outFile << "\n";
    }
    //std::copy(writeVal, writeVal+fileLength, outStream);
    
}

void TestFilter::fileWrite( float *writeVal, const char* fileName, const int &fileLength, const int &numChannels ) const {

    std::ofstream outFile( fileName );
    std::ostream_iterator<float> outStream( outFile, "\n" );
    std::copy(writeVal, writeVal+fileLength, outStream);
    
}
