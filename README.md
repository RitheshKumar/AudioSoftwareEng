# AudioSoftwareEng
# Group Member: Liang Tang & Rithesh Kumar
# Repo for the Assignment 1, MUSI8903, Spring 2016

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Description of our files:
MUSI8903Exec   -> Main function: run the test and the filter processor
Buffering      -> circular buffer class
Filter         -> Base class for FIR and IIR filter
FIRCombFilter  -> Implementation of FIRCombFilter. Derived from Filter class
IIRCombFilter  -> Implementation of IIRCombFilter. Derived from Filter class
TestBuffering  -> Test for the functionality of circular buffer 
TestFilter     -> Test for the functionality of both IIR and FIR filter
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

1, Design a class interface based on the template

To make our interface more intuitive for user, we ask user to pass in five parameters including: the absolute path of the audio sample; block size; delay time in seconds; comb filter gain; filter type which is either FIR and IIR. After processing the audio sample, the application suppose to write the output into a text file which has same name, locating at the same directory of the input audio sample.

User is able to change the block size during the processing. Correspondingly, the block size would be passed into our memory allocation function, The delay time in seconds, sample rate of the audio sample, and the filter gain would be passed into the constructor of either FIRCombFilter or IIRCombFilter. Both of our filter should work with any sample rate. To verify that, we used impulse signal which the sample rate is 100, and a 2s sine wave which the sample rate is 44100 with varied block size in. We compared the output from the DAFX Matlab script and our filter. The max value of the absolute difference between each sample value at same index was employed as the performance validation parameter. As for the all zero and impulse signal, this parameter equals to 0, which means the output of Matlab and our filter are exactly same. As for the 2s sine wave, this parameter went to 0.0000017. This might be caused by the precision differences between double and float. The filter still works well. This filter is based on the circular buffer, and block-wise processing. Once the memory was allocated based on the block length, the audio sample will be processed in place. It doesn't need to be allocated other memory to do the processing.  

The filter was designed for processing arbitary number of channels of audio file, however, it didn't work as it supposed to be. The difference between the output from matlab and our filter is large. After debugging, we found the issue was in the Filter class. Basically, when the signal 


2, Implement FIR comb filter
The implementation is in FIRCombFilter class. Circular buffer was employeed to implement the delay line.

3, Implement IIR comb filter
The implementation is in IIRCombFilter class. Circular buffer was employeed to implement the delay line.

4, Implement main command line funcion
In the main function, we ask user to pass in five parameters, including: the absolute path of the audio sample; block size (int); delay time in seconds (float); comb filter gain (float); filter type (0 or 1)which is either FIR or IIR. After processing the audio sample, the application suppose to write the output into a text file which has same name, locating at the same directory of the input audio sample.

	Argument list:
	1, audio file path (without '.wav')
	2, block size
	3, delay length in seconds
	4, filter gain (from 0 to 1)
	5, filter type: 0 for FIR, 1 for IIR

5, verify functionality for 2 different input audio files by comparison with Matlab
	1, test with impulse signal: the output of matlab and our filter is identical
	2, test with sine wave: the output of matlab and our filter is not exactly the same but within a small range (e to the power of -5).


6, write the following test functions to ensure functionality

	1, zero output if input frequency matches feedforward (FIR)
		We calculate the frequency based on the delay length in seconds with the equation: f = 1 / delayLength / 2. At this input frequency, the output will be 0 if gain of filter is 1.
	2, magnitude increase/decrease if input frequency matches feedback
		For IIR, magnitude will increase if input frequency matches feedback. Given to specific frequency, the delay length in seconds can be calculated by: 1 / frequency
	3, varying input block size (FIR & IIR)
		We use different block size, such as 100, 512, 1024, 4096 to test the functionality. The filter works well.
	4, zero input signal (FIR & IIR)
		When the input signal is zero, both FIR and IIR outputs zero.
	5, additional test to verify correct functionality
		Since we use circular buffer to implement the delay line, we test the functionality of pointer wrap around, and the shifting of writing and reading pointer is at the same pace.


