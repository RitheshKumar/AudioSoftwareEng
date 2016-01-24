#include "FIRCombFilter.h"

FIRCombFilter::FIRCombFilter( float *audioFile, const int &fileLength, const float &delayInSec, const float &sampleRateInHz, const float &gain) : Filter(delayInSec, sampleRateInHz, gain ), _fCurVal(0.0) {

    //std::cout<<"Hi from FIRComb "<<std::endl;
    buffer = new Buffering( _iDelayInSamples );
    
}

FIRCombFilter::~FIRCombFilter() {
    //std::cout<<"Goodbye from FIRComb" <<std::endl;
    delete buffer; 
}

void FIRCombFilter::filterProcess( float *audioFile, const int &fileLength) {

    for( int i=0; i<fileLength; i++ ) {

        buffer->write( audioFile[i] );
        _fCurVal = audioFile[i] + buffer->read()*_fGain;
        audioFile[i] = _fCurVal;

    }
}
