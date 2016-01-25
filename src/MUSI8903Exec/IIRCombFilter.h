#ifndef __IIRCombFilter__
#define __IIRCombFilter__

#include "Filter.h"
#include "Buffering.h"

class IIRCombFilter : public Filter {

    Buffering* _pBuffer;
    float      _fCurVal;

public:

    IIRCombFilter( float *audioFile, const int &fileLength, const float &delayInSec, const float &sampleRateInHz, const float &gain);
    //The IIR constructor should also initiate buffering
    //IIRCombFilter( float *audioFile, const int &fileLength, const float &delayInSec, const float &sampleRateInHz, const float &gain, Buffering buffer);

    ~IIRCombFilter(); 

    void filterProcess( float *audioFile, const int &fileLength);

};

#endif 
