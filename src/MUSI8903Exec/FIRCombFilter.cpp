#include "FIRCombFilter.h"


FIRCombFilter::FIRCombFilter(const float &delayInSec, const float &sampleRateInHz, const float &gain) : Filter(delayInSec, sampleRateInHz, gain ) {
    
    //std::cout<<"Hi from FIRComb "<<std::endl;
    _pBuffer = new Buffering( _iDelayInSamples );
    _fCurVal = 0.0;
}


FIRCombFilter::~FIRCombFilter() {
    //std::cout<<"Goodbye from FIRComb" <<std::endl;
    delete _pBuffer;
    _pBuffer = NULL;
}

void FIRCombFilter::filterProcess( float *audioFile, const int &fileLength) {

    for( int i=0; i<fileLength; i++ ) {

        _pBuffer->write( audioFile[i] );
        _fCurVal = audioFile[i] + _pBuffer->read()*_fGain;
        audioFile[i] = _fCurVal;

    }
}
