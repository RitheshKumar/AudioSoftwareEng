
#include <iostream>
#include <ctime>

#include "MUSI8903Config.h"

#include "AudioFileIf.h"
#include "IIRCombFilter.h"
#include "FIRCombFilter.h"
#include "TestBuffering.h"
#include "TestFilter.h"

using std::cout;
using std::endl;

// local function declarations
void    showClInfo ();

/////////////////////////////////////////////////////////////////////////////////
// main function
int main(int argc, char* argv[])
{
    std::string             _sInputFilePath,                 //!< file paths
                            _sOutputFilePath;

    long long               _llBlockLength      = 0;        //!< length of block
    
    float                   _fDelayLenInSec     = 0.0f;     //!< delay Length in Seconds

    float                   _fGain              = 0.0f;

    clock_t                 time                = 0;

    float                   **ppfAudioData      = 0;

    CAudioFileIf            *phAudioFile        = 0;
    
    std::ofstream            outFile;

    Filter * _FilterProcess;
    
    showClInfo ();
    
    //////////////////////////////////////////////////////////////////////////////
    // Testing
    
    //    Test for Buffer class
        TestBuffering tTestBuf( 100 );
        std::cout<<"Testing the Buffering Class. The result is shown below: 1 represents success, 0 represents failure. "<<std::endl;
        std::cout<<"Initialization: "<<tTestBuf.isInit()<<std::endl;
        std::cout<<"Writing       : "<<tTestBuf.isReadWrite()<< "\n"<<std::endl;
    
    //////////////////////////////////////////////////////////////////////////////
    // Test for Filter classes
    ///////////////////////////////////////////////////
    // Filter Test: IIR naive test
    
        TestFilter testee1(1);
        testee1.zeroInputTest();
        testee1.unitImpulseTest();
        std::cout << "The output of IIR Filter test has been written to a text file at ../bin/debug/ " << std::endl;
    //////////////////////////////////////////////////
    // Filter Test: FIR naive test
    
        TestFilter testee2(0);
        testee2.zeroInputTest();
        testee2.unitImpulseTest();
        std::cout << "The output of FIR Filter test has been written to a text file at ../bin/debug/ \n" << std::endl;

        std::cout << "Use audioFileTest() in TestFilter class for more evaluation results\n\n";    

    //////////////////////////////////////////////////////////////////////////////
    // parse command line arguments
    if (argc<6) {
        std::cerr << "The arguments are not properly provided. Filter cannot be used." << std::endl;
        return -1;
    }
    else {
        _sInputFilePath   = argv[1];
        _sOutputFilePath  = _sInputFilePath + ".txt";
  
        _llBlockLength     = atoi(argv[2]);
        _fDelayLenInSec   = (float) (atof(argv[3]));
        _fGain            = (float) (atof(argv[4]));

    }
    
    //////////////////////////////////////////////////////////////////////////////
    // open the input wave file
    CAudioFileIf::FileIoType_t fileType = CAudioFileIf::kFileRead;
    CAudioFileIf::create(phAudioFile);
    
    phAudioFile -> openFile(_sInputFilePath+".wav", fileType);
    
    CAudioFileIf::FileSpec_t fileSpec;
    phAudioFile -> getFileSpec(fileSpec);
    
    //////////////////////////////////////////////////////////////////////////////
    // allocate memory
   
    time = clock();

    if (atoi(argv[5]) == 0) {
        _FilterProcess = new class FIRCombFilter(_fDelayLenInSec, fileSpec.fSampleRateInHz, _fGain, fileSpec.iNumChannels);
    }
    else if(atoi(argv[5]) == 1) {
        _FilterProcess = new class IIRCombFilter(_fDelayLenInSec, fileSpec.fSampleRateInHz, _fGain, fileSpec.iNumChannels);
    }
    else {
        std::cout << "Filter Type Selection Error. Please select 0 or 1" << std::endl;
        return -1;
    }

    ppfAudioData = new float* [fileSpec.iNumChannels];
    for (int channel = 0; channel < fileSpec.iNumChannels; channel++) {
        ppfAudioData[channel] = new float [_llBlockLength];
    }
    outFile.open(_sOutputFilePath);
    
    // process the signal
    while (!phAudioFile->isEof()) {
        phAudioFile -> readData(ppfAudioData, _llBlockLength);
        for (int channel=0; channel<fileSpec.iNumChannels; channel++ ) {
            _FilterProcess -> filterProcess(ppfAudioData[channel], _llBlockLength, channel);
        }
        for ( int sample = 0; sample < _llBlockLength; sample++ ) {
            for ( int channel = 0; channel < fileSpec.iNumChannels; channel++ ) {
                outFile << ppfAudioData[channel][sample]<<"\t";
            }
            outFile << "\n";
        }
    }
    outFile.close();

    //////////////////////////////////////////////////////////////////////////////
    // clean-up
    delete _FilterProcess;
    for (int channel = 0; channel < fileSpec.iNumChannels; channel++) {
        delete [] ppfAudioData[channel];
    }
    delete [] ppfAudioData;
    std::cout << "Comb filter processing is done within " << (clock() - time)*1.f / CLOCKS_PER_SEC << " seconds." << std::endl;
    CAudioFileIf::destroy(phAudioFile);
    
    return 0;
}


void     showClInfo()
    {
        cout << "GTCMT MUSI8903" << endl;
        cout << "(c) 2016 by Liang Tang and Rithesh Kumar" << endl;
        cout  << endl;
        
        return;
    }

