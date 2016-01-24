#include <iostream>

class Buffering {
    int _iBufferLen, _iDelayLen; //Try implementing your buffer in a radix size!
    float *_pfBuffer, *_pfWrite, *_pfRead;

public:


    Buffering( int delayLen ); 

    ~Buffering(); 
    Buffering( const Buffering &rhs ); 
    Buffering & operator= ( const Buffering &rhs );

    void init();
    void copyBuffer(float *destination, const float *source);

    void update( float *& bufPtr );
    float read();
    void write(const float& val);

};



