#include "IIRCombFilter.h"

IIRCombFilter::IIRCombFilter( float *audioFile, const int &fileLength, const float &delayInSec, const float &sampleRateInHz, const float &gain) : Filter(delayInSec, sampleRateInHz, gain ), _fCurVal(0.0) {

    //std::cout<<"Hi from IIRComb "<<std::endl;
    buffer = new Buffering( _iDelayInSamples );
    
}

IIRCombFilter::~IIRCombFilter() {
    //std::cout<<"Goodbye from IIRComb" <<std::endl;
    delete buffer; 
}

void IIRCombFilter::filterProcess( float *audioFile, const int &fileLength) {

    for( int i=0; i<fileLength; i++ ) {

        _fCurVal = audioFile[i] + buffer->read()*_fGain;
        buffer->write( _fCurVal );
        audioFile[i] = _fCurVal;

    }
}

