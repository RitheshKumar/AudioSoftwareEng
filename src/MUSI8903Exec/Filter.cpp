#include  "Filter.h"

//Filter::Filter ( const float &delayInSec, const float &sampleRateInHz, const float &gain) : _iDelayInSamples( sampleRateInHz*delayInSec ), _fDelayInSec( delayInSec ), _fGain ( gain ) {
//    //std::cout<<"Hi from Filter\n";
//}

Filter::Filter ( const float &delayInSec, const float &sampleRateInHz, const float &gain) : _fDelayInSec( delayInSec ), _iDelayInSamples( (int)(sampleRateInHz*delayInSec) ),  _fGain ( gain ) {
    
    //std::cout<<"Hi from Filter\n";
    
}

Filter::~Filter() {
    //std::cout<<"Goodbye from Filter"<<std::endl;
}
