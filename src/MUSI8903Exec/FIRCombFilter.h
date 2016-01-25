#ifndef __FIRCombFilter__
#define __FIRCombFilter__

#include "Filter.h"
#include "Buffering.h"

class FIRCombFilter : public Filter {

    Buffering* _pBuffer;
    float      _fCurVal;

public:

    FIRCombFilter( float *audioFile, const int &fileLength, const float &delayInSec, const float &sampleRateInHz, const float &gain);
    FIRCombFilter(const float &delayInSec, const float &sampleRateInHz, const float &gain);

    ~FIRCombFilter(); 

    void filterProcess( float *audioFile, const int &fileLength);

};

#endif 
