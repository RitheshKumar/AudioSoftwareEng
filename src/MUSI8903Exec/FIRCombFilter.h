#ifndef __FIRCombFilter__
#define __FIRCombFilter__

#include "Filter.h"
#include "Buffering.h"

class FIRCombFilter : public Filter {

    Buffering** _ppBuffer;
    float       _fCurVal;
    int         _iNumChannels;

public:
    // Constructor
    FIRCombFilter(const float &delayInSec, const float &sampleRateInHz, const float &gain, const int &numChannels);
    // Destructor
    ~FIRCombFilter(); 
    // This is implementation of FIR Comb Filter from the DAFX book
    // Pass in the float pointer, and the length of audio
    void filterProcess( float *audioFile, const int &fileLength, const int channel);

};

#endif 
