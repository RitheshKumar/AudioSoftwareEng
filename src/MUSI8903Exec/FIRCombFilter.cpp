#include "FIRCombFilter.h"

// Constructor
FIRCombFilter::FIRCombFilter(const float &delayInSec, const float &sampleRateInHz, const float &gain) : Filter(delayInSec, sampleRateInHz, gain ) {
    
    //std::cout<<"Hi from FIRComb "<<std::endl;
    _pBuffer = new Buffering( _iDelayInSamples );
    _fCurVal = 0.0;
}

// Destructor
FIRCombFilter::~FIRCombFilter() {
    //std::cout<<"Goodbye from FIRComb" <<std::endl;
    delete _pBuffer;
    _pBuffer = NULL;
}

// This is implementation of FIR Comb Filter from the DAFX book
// Pass in the float pointer, and the length of audio
void FIRCombFilter::filterProcess( float *audioFile, const int &fileLength) {

    for( int i=0; i<fileLength; i++ ) {

        _pBuffer->write( audioFile[i] );
        _fCurVal = audioFile[i] + _pBuffer->read()*_fGain;
        audioFile[i] = _fCurVal;

    }
}
