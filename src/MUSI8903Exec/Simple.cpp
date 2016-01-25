#include <iostream>
#include "TestBuffering.h"

bool isZeros( float *fArray, int len ) {
    for ( int i =0; i<len; i++ ) {
        if ( fArray[i] != 0 ) {
            return false;
        }
    }
    return true;
}


int main () {
    float *fArray = new float [20];

    for( int i=0; i<20; i++ ) {
        fArray[i] = 0.0;
    }

    fArray[19] = 1;

    //std::cout<<isZeros( fArray, 20 )<<std::endl;

    int idelayLen = 512;
    TestBuffering tTestBuf( idelayLen );
    std::cout<<"Initialization: "<<tTestBuf.isInit()<<std::endl;
    std::cout<<"Writing       : "<<tTestBuf.isReadWrite()<<std::endl;

    return 0;
}

