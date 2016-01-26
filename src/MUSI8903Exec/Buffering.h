#ifndef __Buffering__
#define __Buffering__

#include <iostream>

class Buffering {
    int _iDelayLen, _iBufferLen; //Try implementing your buffer in a radix size!
    float *_pfBuffer, *_pfWrite, *_pfRead, *_pfEnd;

public:

    // Constructor
    Buffering( int delayLen );
    
    // Destructor
    ~Buffering();
    
    // Copy Constructor
    Buffering( const Buffering &rhs );
    
    // Override operator =
    Buffering & operator = ( const Buffering &rhs );
    
    // This init function is called by this constructor
    void init();
    
    void copyBuffer(float *destination, const float *source);
    
    // This update function moves the pointer and handle the wrap around
    void update( float *& bufPtr );
    
    // Read and return the audio sample from the buffer
    float read();
    
    // write in the audio sample to the buffer
    void write(const float& val);

    // return the buffer length
    int getBufferLen() { return _iBufferLen; }

};

#endif
