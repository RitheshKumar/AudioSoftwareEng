
#include <iostream>
#include <ctime>

#include "MUSI8903Config.h"

#include "AudioFileIf.h"

using std::cout;
using std::endl;

// local function declarations
void    showClInfo ();

/////////////////////////////////////////////////////////////////////////////////
// main function
int main(int argc, char* argv[])
{
    std::string             sInputFilePath,                 //!< file paths
                            sOutputFilePath;

    long long               iInFileLength       = 0;        //!< length of input file

    clock_t                 time                = 0;

    float                   **ppfAudioData      = 0;

    CAudioFileIf            *phAudioFile        = 0;

    enum eFilterTypes {
        FIRCombFilter = 1,
        IIRCombFilter = 2
    };
    
    int iTypeOfFilter = 0;
    
    float fDelayInSec = 0.f;
    
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
    if (argc<2) {
        return -1;
    }
    else {
        sInputFilePath = argv[1];
        sOutputFilePath  = sInputFilePath + ".txt";
//        std::cout<<sOutputFilePath<<std::endl;
    }
    
    //////////////////////////////////////////////////////////////////////////////
    // open the input wave file
    CAudioFileIf::FileIoType_t fileType = CAudioFileIf::kFileRead;
    CAudioFileIf::create(phAudioFile);
    
    phAudioFile -> openFile(sInputFilePath, fileType);
    
    CAudioFileIf::FileSpec_t fileSpec;
    phAudioFile -> getFileSpec(fileSpec);
    int numChannels = fileSpec.iNumChannels;
    
    phAudioFile -> getLength(iInFileLength);
    //////////////////////////////////////////////////////////////////////////////
    // allocate memory
    ppfAudioData = new float* [numChannels];
    
    for (int channel = 0; channel < numChannels; channel++) {

    }
    
    
    // get audio data
    

    //////////////////////////////////////////////////////////////////////////////
    // do processing
    
    cout << "Processing is done!" << endl << endl;

    //////////////////////////////////////////////////////////////////////////////
    // clean-up
    for (int channel = 0; channel < numChannels; channel++) {
        delete ppfAudioData[channel];
    }
    delete ppfAudioData;
    
    CAudioFileIf::destroy(phAudioFile);
    
    return 0;
    
}


void     showClInfo()
{
    cout << "GTCMT MUSI8903" << endl;
    cout << "(c) 2016 by Alexander Lerch" << endl;
    cout  << endl;

    return;
}

