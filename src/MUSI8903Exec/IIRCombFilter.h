#ifndef __IIRCombFilter__
#define __IIRCombFilter__

#include "Filter.h"
#include "Buffering.h"


class IIRCombFilter : public Filter {

    Buffering* _pBuffer;
    float      _fCurVal;

public:
    // Constructor
    IIRCombFilter( const float &delayInSec, const float &sampleRateInHz, const float &gain);
    // Destructor
    ~IIRCombFilter(); 
    // This is implementation of IIR Comb Filter from the DAFX book
    // Pass in the float pointer, and the length of audio
    void filterProcess( float *audioFile, const int &fileLength);

};

#endif 
