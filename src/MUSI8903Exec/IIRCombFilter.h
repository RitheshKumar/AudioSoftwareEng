#ifndef __IIRCombFilter__
#define __IIRCombFilter__

#include "Filter.h"
#include "Buffering.h"


class IIRCombFilter : public Filter {

    Buffering** _ppBuffer;
    float      _fCurVal;
    int _iNumChannels;

public:
    // Constructor
    IIRCombFilter( const float &delayInSec, const float &sampleRateInHz, const float &gain, const int &numChannels);
    // Destructor
    ~IIRCombFilter(); 
    // This is implementation of IIR Comb Filter from the DAFX book
    // Pass in the float pointer, and the length of audio
    void filterProcess( float *audioFile, const int &fileLength, const int channel);

};

#endif 
