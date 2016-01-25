#ifndef __TestBuffering__
#define __TestBuffering__

#include<iostream>
#include "Buffering.h"


class TestBuffering {
    Buffering *_pBuffer;
    int _iDelayLen, _iBufferLen;

public:

    TestBuffering( const int &delayLen );

    ~TestBuffering();

    bool isInit(); //Check if the buffer is initialized to zero

    bool isReadWrite(); //Check the write functionality of Buffering class
};

#endif
