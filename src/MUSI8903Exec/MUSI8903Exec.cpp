
#include <iostream>
#include <ctime>

#include "MUSI8903Config.h"

#include "AudioFileIf.h"
#include "IIRCombFilter.h"
#include "FIRCombFilter.h"

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

//    long long               _llInFileLength       = 0;        //!< length of input file

    long long               _llBlockLength        = 0;        //!< length of block
    
    float                   _fDelayLenInSec      = 0.0f;     //!< delay Length in Seconds

    float                   _fGain               = 0.0f;

    clock_t                 time                = 0;

    float                   **ppfAudioData      = 0;

    CAudioFileIf            *phAudioFile        = 0;

//    FIRCombFilter           *pFIRFilter;
//    IIRCombFilter           *pIIRFilter;
    Filter * _FilterProcess;


    enum eFilterTypes {
        FIRCombFilter,
        IIRCombFilter
    };
    
//    int iTypeOfFilter = 0;
    
//    float _fDelayInSec = 0.f;
    
    showClInfo ();

    //////////////////////////////////////////////////////////////////////////////
    // parse command line arguments
//    if (argc <= 0 || argc > 10) {
//        std::cerr << "The arguments are not properly provided" << std::endl;
//    } else {
//        sInputFilePath = argv[0];
//        iTypeOfFilter = eFilterTypes.argv[1];
//        fDelayInSec = (float)argv[2];
//    }
    if (argc<4) {
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
    
    phAudioFile -> openFile(_sInputFilePath, fileType);
    
    CAudioFileIf::FileSpec_t fileSpec;
    phAudioFile -> getFileSpec(fileSpec);
    
    //////////////////////////////////////////////////////////////////////////////
    // allocate memory
   
    time = clock();
    ppfAudioData = new float* [fileSpec.iNumChannels];
    for (int channel = 0; channel < fileSpec.iNumChannels; channel++) {
        ppfAudioData[channel] = new float [_llBlockLength];
    }
    while (!phAudioFile->isEof()) {
        phAudioFile -> readData(ppfAudioData, _llBlockLength);
        if (atoi(argv[5]) == 0) {
            for (int i = 0; i < fileSpec.iNumChannels; i++) {
                _FilterProcess = new class FIRCombFilter(_fDelayLenInSec, fileSpec.fSampleRateInHz, _fGain);
                _FilterProcess -> filterProcess(ppfAudioData[i], _llBlockLength);
            }
        } else if (atoi(argv[5]) == 1){
            for (int i = 0; i < fileSpec.iNumChannels; i++) {
                _FilterProcess = new class IIRCombFilter(_fDelayLenInSec, fileSpec.fSampleRateInHz, _fGain);
                _FilterProcess -> filterProcess(ppfAudioData[i], _llBlockLength);
            }

        } else {
            std::cout << "Filter Type Selection Error. Please select 0 or 1" << std::endl;
        }
    }
    delete _FilterProcess;
    
    std::cout << "Processing is done within " << (clock() - time)*1.f / CLOCKS_PER_SEC << " seconds." << std::endl;
    
    CAudioFileIf::destroy(phAudioFile);


    //////////////////////////////////////////////////////////////////////////////
    // clean-up
//    for (int channel = 0; channel < numChannels; channel++) {
//        delete [] ppfAudioData[channel];
//    }
//    delete [] ppfAudioData;
//    
//    CAudioFileIf::destroy(phAudioFile);
//    
//    return 0;
//    
//}
}

void     showClInfo()
    {
        cout << "GTCMT MUSI8903" << endl;
        cout << "(c) 2016 by LiangTang and Ritesh Kumar" << endl;
        cout  << endl;
        
        return;
    }

