#include <iostream>

class Buffering {
    int _iBufferLen, _iDelayLen; //Try implementing your buffer in a radix size!
    float *_pfBuffer, *_pfWrite, *_pfRead;

public:

    void init();
    void copyBuffer(float *destination, const float *source);

    Buffering( int delayLen ); 

    ~Buffering(); 
    Buffering( const Buffering &rhs ); 
    Buffering & operator= ( const Buffering &rhs );

    void update( float *& bufPtr );
    float read();
    float write();

};



