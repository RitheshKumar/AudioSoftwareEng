#ifndef __Filter__
#define __Filter__

#include <iostream>

class Filter {

protected:
    float _fDelayInSec;
    int _iDelayInSamples;
    float _fGain;

public:
    // Constructor
    Filter ( const float &delayInSec, const float &sampleRateInHz, const float &gain) ;
    // Destructor
    virtual ~Filter();
    // Pure virtual function
    virtual void filterProcess(float *audioFile, const int &fileLength) = 0;
};

#endif
