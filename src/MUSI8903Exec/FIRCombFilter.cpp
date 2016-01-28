#include "FIRCombFilter.h"

// Constructor
FIRCombFilter::FIRCombFilter(const float &delayInSec, const float &sampleRateInHz, const float &gain, const int &numChannels) : Filter(delayInSec, sampleRateInHz, gain ), _iNumChannels( numChannels ) {
    
    //std::cout<<"Hi from FIRComb "<<std::endl;
    _ppBuffer = new Buffering* [numChannels];
    for( int channel=0; channel<numChannels; channel++ ) {
        _ppBuffer[channel] = new Buffering(_iDelayInSamples);
    }
    _fCurVal = 0.0;
}

// Destructor
FIRCombFilter::~FIRCombFilter() {
    //std::cout<<"Goodbye from FIRComb" <<std::endl;
    for( int channel=0; channel<_iNumChannels; channel++ ) {
        delete _ppBuffer[channel];
    }
    delete []_ppBuffer; 
    _ppBuffer = NULL;
}

// This is implementation of FIR Comb Filter from the DAFX book
// Pass in the float pointer, and the length of audio
void FIRCombFilter::filterProcess( float *audioFile, const int &fileLength, const int channel) {
    for( int i=0; i<fileLength; i++ ) {
        _ppBuffer[channel]->write( audioFile[i] );
        _fCurVal = audioFile[i] + _ppBuffer[channel]->read()*_fGain;
        audioFile[i] = _fCurVal;
    }
}
