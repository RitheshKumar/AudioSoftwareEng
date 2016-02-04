//Project Header
#include "MUSI8903Config.h"

#include "Buffering.h"


void Buffering::init() {
    if (!_pfBuffer) {
        delete _pfBuffer;  
    }
    _pfBuffer = new float[_iBufferLen]; //Allocate Memory
    //Initialize to zero
    for ( int i = 0; i < _iBufferLen; i++ ) {
        _pfBuffer[i] = 0.0;
    }
    _pfRead   = _pfBuffer;
    _pfWrite  = _pfRead + _iDelayLen;
    _pfEnd    = _pfBuffer + _iBufferLen;
}

void Buffering::copyBuffer(float *destination, const float *source) {
    for (int i =0; i<_iBufferLen; i++ ) {
        destination[i] = source[i];
    }
}

Buffering::Buffering( int delayLen ) : _iDelayLen( delayLen ), _iBufferLen( 4*delayLen ), _pfBuffer( 0 ) {
    init();
}

Buffering::~Buffering() {
    delete _pfBuffer;
    _pfBuffer = NULL;
    _pfWrite  = NULL;
    _pfRead   = NULL;
}

Buffering::Buffering( const Buffering &rhs ) : _iDelayLen( rhs._iDelayLen ), _iBufferLen( rhs._iBufferLen )  {
    init();
    copyBuffer( _pfBuffer, rhs._pfBuffer );
}

Buffering & Buffering::operator= ( const Buffering &rhs ) {
    if ( this != &rhs ) { //If the addresses are not the same

    _iBufferLen    = rhs._iBufferLen;
    _iDelayLen     = rhs._iDelayLen;

    init();
    copyBuffer( _pfBuffer, rhs._pfBuffer );

    }
    return *this;
}

void Buffering::update( float *& bufPtr ) {
    if ( bufPtr != _pfEnd ) {
        bufPtr++;
    }
    else {
        bufPtr = _pfBuffer;
    }
}

float Buffering::read() {
    float out = *_pfRead;
    update( _pfRead );
    return out;
}

void Buffering::write(const float& val) {
    *_pfWrite = val;
    update( _pfWrite );
}

            



