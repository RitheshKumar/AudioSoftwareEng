#include "TestBuffering.h"



TestBuffering::TestBuffering( const int &delayLen ) : _pBuffer( new Buffering( delayLen ) ), _iDelayLen( delayLen ), _iBufferLen( 4*delayLen )  {
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
    }
    return true;
}

bool TestBuffering::isReadWrite() { //Check the read/write functionality of Buffering class
    //By default, read points to the first element  of the buffer, 
    //write points _iDelayLen away from read

    for( int i = 0; i < _iBufferLen; i++) { //by the end of the loop, the write pointer must point to the initial position
        _pBuffer->write( i*1.0f );
    }

    if ( _pBuffer->read() != _iBufferLen-_iDelayLen ) {
        return false;
    }

    return true;
}
