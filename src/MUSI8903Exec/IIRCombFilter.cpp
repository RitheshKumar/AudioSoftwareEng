#include "IIRCombFilter.h"


IIRCombFilter::IIRCombFilter( const float &delayInSec, const float &sampleRateInHz, const float &gain): Filter(delayInSec, sampleRateInHz, gain) {
    
    _pBuffer = new Buffering( _iDelayInSamples );
    _fCurVal = 0.0;
    
}



IIRCombFilter::~IIRCombFilter() {
    //std::cout<<"Goodbye from IIRComb" <<std::endl;
    delete _pBuffer; 
    _pBuffer = NULL;
}

void IIRCombFilter::filterProcess( float *audioFile, const int &fileLength) {

    for( int i=0; i<fileLength; i++ ) {

        _fCurVal = audioFile[i] + _pBuffer->read()*_fGain;
        _pBuffer->write( _fCurVal );
        audioFile[i] = _fCurVal;

    }
};

