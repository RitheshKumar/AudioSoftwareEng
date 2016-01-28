#include  "Filter.h"

Filter::Filter ( const float &delayInSec, const float &sampleRateInHz, const float &gain) : _fDelayInSec( delayInSec ), _iDelayInSamples( (int)(sampleRateInHz*delayInSec) ),  _fGain ( gain ) {
}

Filter::~Filter() {

}
