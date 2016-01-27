# AudioSoftwareEng
# Group Member: Liang Tang & Rithesh Kumar

Repo for the Assignment 1, MUSI8903, Spring 2016

Problem
1, can we write within the header file instead of cpp file as long as it is one line of code
2, Testing
1, Testing buffering: script in the simple.cpp
2, Getting the output of FIR and IIR comb filter with the input of zero input and impulse
3, Getting the output of FIR and IIR comb filter with the input of audio file
4, Comparing the result of 3, and 4, to their correspondings from DAFX Matlab code
3, writing the main function

Answers to the Questions in T-Square
1, To make our interface more intuitive for user, we ask user to pass in five parameters including: the absolute path of the audio sample; block size; delay time in seconds; comb filter gain; filter type which is either FIR and IIR. After processing the audio sample, the application suppose to write the output into a text file locating at the same directory of the input audio sample.

User is able to change the block size during the processing. Correspondingly, the block size would be passed into our memory allocation function, and the delay time in seconds, sample rate of the audio sample, and the filter gain would be passed into the constructor of FIRCombFilter or IIRCombFilter. Both of our filter should work with any sample rate. To verify that, we test the filter with impulse signal which the sample rate is 100, and a 2s sine wave which the sample rate is 44100. We compared the output from the DAFX Matlab script and our filter. The summation of the absolute difference between each sample value at same index was employed as the performance validation parameter. As for the all zero and impulse signal, this parameter equals to 0, which means the output of Matlab and our filter are exactly same. As for the 2s sine wave, this parameter went to 1.5. To find the reason of it, 1.5 was divided by 88200 which is the number of samples for 2s sine wave. The average absolute difference was 0.00001. This might be caused by the precision between double and float.

This filter was designed to work with arbitrary channels, since the application try to get the number of channel from the audio sample, and use a for loop to loop through all the channels one by one, and do the same process towards each. 

This filter is based on the circular buffer, and block-wise processing. It is inplace process.