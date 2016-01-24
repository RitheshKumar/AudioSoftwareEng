#include <iostream>

class Filter {

protected:
    float _fGain, _fDelayInSec;
    int _iDelayInSamples;

public:

    Filter ( const float &delayInSec, const float &sampleRateInHz, const float &gain) ;

    virtual ~Filter();
    
};
