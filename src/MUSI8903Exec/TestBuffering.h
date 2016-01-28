#ifndef __TestBuffering__
#define __TestBuffering__

// This class is designed for testing the Buffering class
#include<iostream>
#include "Buffering.h"


class TestBuffering {
    Buffering *_pBuffer;
    int _iDelayLen;

public:

    TestBuffering( const int &delayLen );

    ~TestBuffering();

    bool isInit(); //Check if the buffer is initialized to zero

    bool isReadWrite(); //Check the write functionality of Buffering class
};

#endif
