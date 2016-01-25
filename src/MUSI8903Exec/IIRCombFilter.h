#ifndef __IIRCombFilter__
#define __IIRCombFilter__

#include "Filter.h"
#include "Buffering.h"

class IIRCombFilter : public Filter {

    Buffering* _pBuffer;
    float      _fCurVal;

public:

    IIRCombFilter( float *audioFile, const int &fileLength, const float &delayInSec, const float &sampleRateInHz, const float &gain);
    IIRCombFilter( const float &delayInSec, const float &sampleRateInHz, const float &gain);


    ~IIRCombFilter(); 

    void filterProcess( float *audioFile, const int &fileLength);

};

#endif 
