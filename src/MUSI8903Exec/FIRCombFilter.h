#ifndef __FIRCombFilter__
#define __FIRCombFilter__

#include "Filter.h"
#include "Buffering.h"

class FIRCombFilter : public Filter {

    Buffering* _pBuffer;
    float      _fCurVal;

public:
    // Constructor
    FIRCombFilter(const float &delayInSec, const float &sampleRateInHz, const float &gain);
    // Destructor
    ~FIRCombFilter(); 
    // This is implementation of FIR Comb Filter from the DAFX book
    // Pass in the float pointer, and the length of audio
    void filterProcess( float *audioFile, const int &fileLength);

};

#endif 
