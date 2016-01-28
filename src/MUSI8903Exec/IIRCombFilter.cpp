#include "IIRCombFilter.h"

// Constructor
IIRCombFilter::IIRCombFilter( const float &delayInSec, const float &sampleRateInHz, const float &gain, const int &numChannels): Filter(delayInSec, sampleRateInHz, gain), _iNumChannels(numChannels) {
    
    _ppBuffer = new Buffering* [numChannels];
    for( int channel=0; channel<numChannels; channel++ ) {
        _ppBuffer[channel] = new Buffering(_iDelayInSamples);
    }

    _fCurVal = 0.0;
    
}

// Destructor
IIRCombFilter::~IIRCombFilter() {
    //std::cout<<"Goodbye from IIRComb" <<std::endl;
    for( int channel=0; channel<_iNumChannels; channel++ ) {
        delete _ppBuffer[channel];
    }
    delete []_ppBuffer; 
    _ppBuffer = NULL;
}

// This is implementation of IIR Comb Filter from the DAFX book
// Pass in the float pointer, and the length of audio
void IIRCombFilter::filterProcess( float *audioFile, const int &fileLength, const int channel) {

    for( int i=0; i<fileLength; i++ ) {

        _fCurVal = audioFile[i] + ( _ppBuffer[channel]->read() )*_fGain;
        _ppBuffer[channel]->write( _fCurVal );
        audioFile[i] = _fCurVal;

    }
};

