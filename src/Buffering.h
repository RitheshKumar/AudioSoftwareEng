#include <iostream>

class Buffering {
    int _iBufferLen, _iSampleRateHz;
    float *_pfBuffer;
    float **_ppfDelaySample, **_ppfEndOfBuffer;

public:
    Buffering( int bufferInSec, int sampleRate ) : _iBufferLen( bufferInSec*sampleRate ), _iSampleRateHz( sampleRate ) {
        init();
    }
    
    ~Buffering() {
        delete _pfBuffer;
        _pfBuffer = NULL;
        _ppfEndOfBuffer = NULL;
        _ppfDelaySample = NULL;
    }

    Buffering( const & Buffering rhs ) :_iBufferLen( rhs._iBufferLen ), _iSampleRateHz( rhs._iSampleRateHz) {

        init();
        copyBuffer( _pfBuffer, rhs._pfBuffer );

    }

    Buffering & Buffering operator= ( const & Buffering rhs ) {
        if ( this != &rhs ) { //If the addresses are not the same

        _iBufferLen    = rhs._iBufferLen;
        _iSampleRateHz = rhs._iSampleRateHz;

        init();
        copyBuffer( _pfBuffer, rhs._pfBuffer );

        }
        return *this;
    }

    void init() {
        delete _pfBuffer;
        _pfBuffer = new float[_iBufferLen];
        _ppfDelaySample = &_pfBuffer;
        _ppfEndOfBuffer = &( _pfBuffer + _iBufferLen );
    }

    void copyBuffer(float *destination, const float *source) {
        for (int i =0; i<_iBufferLen; i++ ) {
            destination[i] = source[i];
        }
    }
            
};



