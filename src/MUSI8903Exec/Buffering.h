#ifndef __Buffering__
#define __Buffering__

#include <iostream>

class Buffering {
    int _iDelayLen, _iBufferLen; //Try implementing your buffer in a radix size!
    float *_pfBuffer, *_pfWrite, *_pfRead, *_pfEnd;

public:


    Buffering( int delayLen ); 

    ~Buffering(); 
    Buffering( const Buffering &rhs ); 
    Buffering & operator = ( const Buffering &rhs );

    void init();
    void copyBuffer(float *destination, const float *source);

    void update( float *& bufPtr );
    float read();
    void write(const float& val);

    int getBufferLen() { return _iBufferLen; }

};

#endif
