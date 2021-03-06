#include <iostream>
#include <fstream>
#include "TestBuffering.h"
#include "TestFilter.h"

//bool isZeros( float *fArray, int len ) {
//    for ( int i =0; i<len; i++ ) {
//        if ( fArray[i] != 0 ) {
//            return false;
//        }
//    }
//    return true;
//}


int main () {
//    float *fArray = new float [20];
//
//    for( int i=0; i<20; i++ ) {
//        fArray[i] = 1.5f*i;
//    }
//
//    fArray[19] = 8.0f;

    //std::cout<<isZeros( fArray, 20 )<<std::endl;

//    int idelayLen = 512;
//    ////////////////////////////////////////////////////////////////////////////////////////////////////
////    Test for Buffer class
//    TestBuffering tTestBuf( idelayLen );
//    std::cout<<"Initialization: "<<tTestBuf.isInit()<<std::endl;
//    std::cout<<"Writing       : "<<tTestBuf.isReadWrite()<<std::endl;

//    std::ofstream outFile;
//    outFile.open("MyFile.txt");
//    std::ostream_iterator<float> outStream( outFile, "\n" );
//    std::copy(fArray, fArray+20, outStream); //Don't understand why the end pointer is not beginPtr+fileLen-1 but beginPtr+fileLen
//    std::cout<<*(fArray+19)<<std::endl;
    
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    // Test for Filter classes
    ///////////////////////////////////////////////////
//     Filter Test: IIR naive test
//    
//    TestFilter testee1(1);
//    testee1.zeroInputTest();
//    testee1.unitImpulseTest();
    
    //////////////////////////////////////////////////
    // Filter Test: FIR naive test
//    
//    TestFilter testee2(0);
//    testee2.zeroInputTest();
//    testee2.unitImpulseTest();
    
    //////////////////////////////////////////////////
    // Audio File Test
    
    // variable declaration
    long long    iInFileLength  = 0;
    float        **ppfAudioData = 0;
    CAudioFileIf *phAudioFile   = 0;
    
    // provide the path
    std::string sInputFilePath = "/Users/Rithesh/Desktop/test samples/We_Never_Fly_Away_Again.wav";
    //std::string sInputFilePath = "/Users/musictechnology/Desktop/ShortDataset/Calcutta_Cutie.wav";
    
    // get info of the audio file
    CAudioFileIf::FileIoType_t fileType = CAudioFileIf::kFileRead;
    CAudioFileIf::create(phAudioFile);
    
    phAudioFile -> openFile(sInputFilePath, fileType);
    
    CAudioFileIf::FileSpec_t fileSpec;
    phAudioFile -> getFileSpec(fileSpec);
    int numChannels = fileSpec.iNumChannels;
    phAudioFile -> getLength(iInFileLength);
    
    // allocate memory
    ppfAudioData = new float* [numChannels];
    for (int channel = 0; channel < numChannels; channel++) {
        ppfAudioData[channel] = new float [iInFileLength];
    }
    phAudioFile -> readData(ppfAudioData, iInFileLength);
    
    // First argument of this function manage the filter type
    // 1 is IIR
    // 0 is FIR
    TestFilter tester(0, fileSpec.fSampleRateInHz, (.5f), 0.8f, fileSpec.iNumChannels);
    tester.audioFileTest(ppfAudioData, iInFileLength, fileSpec.iNumChannels);


    
    std::cout << "Testing is done!" << std::endl;
    
    CAudioFileIf::destroy(phAudioFile);
    
    
 
    
    //    for (int channel = 0; channel < numChannels; channel++) {
    //        testFIR = new class FIRCombFilter(ppfAudioData[channel], iInFileLength, 1.f, fileSpec.fSampleRateInHz, 0.8f);
    //        if (!_iWhichFilter) {
    //            testFIR -> filterProcess(ppfAudioData[channel], iInFileLength);
    //        } else {
    //            testIIR -> filterProcess(ppfAudioData[channel], iInFileLength);
    //        }
    //
    //        fileWrite(ppfAudioData[channel], "FilterTestForAudioFile.txt");
    //    }
    //
    //
    //    phAudioFile -> getLength(iInFileLength);
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    
    return 0;
}

