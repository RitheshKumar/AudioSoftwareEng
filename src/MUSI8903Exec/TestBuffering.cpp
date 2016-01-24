#include "TestBuffering.h"



TestBuffering::TestBuffering( const int &delayLen ) : _iDelayLen( delayLen ), _iBufferLen( 4*delayLen ), _pBuffer( new Buffering( delayLen ) ) {
}

TestBuffering::~TestBuffering(){
    delete _pBuffer;
    _pBuffer = NULL;
}

bool TestBuffering::isInit() { //Check if the buffer is initialized to zero
    float fTemp;
    for( int i = 0; i < _iBufferLen; i++ ) {
        fTemp = _pBuffer->read(); 
        if( fTemp != 0.0 ) {
            return false;
        }
        std::cout<<fTemp<<std::endl;
    }
    return true;
}

bool TestBuffering::isWrite() { //Check the write functionality of Buffering class
    //By default, read points to the first element  of the buffer, 
    //write points _iDelayLen away from read

    for( int i = 0; i < _iBufferLen; i++) { //Write in values greater than bufferLen
        _pBuffer->write( i*1.0 );
    }

    //Now, we must have values 10 to _iBufferLen in the same indices of the buffer,
    //and have values _iBufferLen+1 to _iBufferLen+10 in the first ten indices

    for( int i=0; i < _iBufferLen; i++ ) {
        std::cout<<_pBuffer->read()<<std::endl;
    }
    return true;
}
