
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
    std::ofstream            outFile;

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

//    for (int blockSize = 0; blockSize<_llBlockLength; blockSize++) {
//        for (int channel = 0; channel< fileSpec.iNumChannels; channel++) {
//            ppfAudioData[channel][blockSize] = 0.0f;
//        }
//    }
    
    outFile.open(_sOutputFilePath);
    
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

    
    //////////////////////////////////////////////////////////////////////////////
//    // Write the file out
//    long long iFileLength;
//
//    phAudioFile->getLength(iFileLength);
//
//    outFile.open(_sOutputFilePath);
//
//    for ( int sample = 0; sample < iFileLength; sample++ ) {
//        for ( int channel = 0; channel < fileSpec.iNumChannels; channel++ ) {
//            outFile << ppfAudioData[channel][sample]<<"\t";
//        }
//        outFile << "\n";
//    }

    outFile.close();

    //////////////////////////////////////////////////////////////////////////////
    // clean-up

    delete _FilterProcess;

    for (int channel = 0; channel < fileSpec.iNumChannels; channel++) {
        delete [] ppfAudioData[channel];
    }
    delete [] ppfAudioData;
    
    std::cout << "Processing is done within " << (clock() - time)*1.f / CLOCKS_PER_SEC << " seconds." << std::endl;

    CAudioFileIf::destroy(phAudioFile);
    
    return 0;
    
}


void     showClInfo()
    {
        cout << "GTCMT MUSI8903" << endl;
        cout << "(c) 2016 by LiangTang and Rithesh Kumar" << endl;
        cout  << endl;
        
        return;
    }

