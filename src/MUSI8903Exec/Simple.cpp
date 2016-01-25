#include <iostream>
#include <fstream>
#include "TestBuffering.h"
#include "TestFilter.h"

bool isZeros( float *fArray, int len ) {
    for ( int i =0; i<len; i++ ) {
        if ( fArray[i] != 0 ) {
            return false;
        }
    }
    return true;
}


int main () {
//    float *fArray = new float [20];
//
//    for( int i=0; i<20; i++ ) {
//        fArray[i] = 1.5f*i;
//    }
//
//    fArray[19] = 8.0f;

    //std::cout<<isZeros( fArray, 20 )<<std::endl;

//    int idelayLen = 512;
//    TestBuffering tTestBuf( idelayLen );
//    std::cout<<"Initialization: "<<tTestBuf.isInit()<<std::endl;
//    std::cout<<"Writing       : "<<tTestBuf.isReadWrite()<<std::endl;

//    std::ofstream outFile;
//    outFile.open("MyFile.txt");
//    std::ostream_iterator<float> outStream( outFile, "\n" );
//    std::copy(fArray, fArray+20, outStream); //Don't understand why the end pointer is not beginPtr+fileLen-1 but beginPtr+fileLen
//    std::cout<<*(fArray+19)<<std::endl;

    //////////////////////////////////////////////////
    // Filter Test
    // IIR Test
    
    TestFilter testee(1);
    testee.zeroInputTest();
    testee.unitImpulseTest();
    
    /////////////////////////////////////////////////
    // FIR Test
    TestFilter testee2(0);
//    testee2.zeroInputTest();
//    testee2.unitImpulseTest();
    
    /////////////////////////////////////////////////
    return 0;
}

