%% A matlab script to evaluate the Comb filter results

clear all; 
close all;
clc;

%% FIR Unit Impulse

x=zeros(100,1);x(1)=1; % unit impulse signal of length 100


FIRAudioOut = FIRCombFilter( x, 30, 0.8, 1 );

fileID=fopen('/Users/Rithesh/Documents/Learn C++/ASE/AudioSoftwareEng/bin/debug/FIRUnitImpulseFilter.txt'); 
	D = textscan(fileID,'%f','Delimiter', '\n', 'CollectOutput', true); 
testee = D{1};

sumOfDiff( FIRAudioOut, testee );

%% IIR Unit Impulse

x=zeros(100,1);x(1)=1; % unit impulse signal of length 100

FilterOut = IIRCombFilter( x, 30, 0.8, 1 ); 

fileID=fopen('/Users/Rithesh/Documents/Learn C++/ASE/AudioSoftwareEng/bin/debug/IIRUnitImpulseFilter.txt'); 
	D = textscan(fileID,'%f','Delimiter', '\n', 'CollectOutput', true); 
testee = D{1};

sumOfDiff( FilterOut, testee );

%% FIR Audio Test
fileID=fopen('/Users/Rithesh/Documents/Learn C++/ASE/AudioSoftwareEng/bin/debug/FIRAudioFileTestResult.txt'); 
D = textscan(fileID,'%f','Delimiter', '\n', 'CollectOutput', true); 
testee = D{1};
testL = testee(1:2:end);    

[x,fs ] = audioread('/Users/Rithesh/Desktop/test samples/We_Never_Fly_Away_Again.wav');
x = x(:,1);

FIRAudioOut = FIRFilter( x, 0.5, 0.8, fs );
TestOut     = sumOfDiff( FIRAudioOut, testL );

%% IIR Audio Test

[x,fs ] = audioread('/Users/Rithesh/Desktop/test samples/We_Never_Fly_Away_Again.wav');
x = x(:,1);
FilterOut = IIRCombFilter( x, 0.5, 0.8, fs ); 

% fileID=fopen('/Users/Rithesh/Desktop/test samples/We_Never_Fly_Away_Again.txt'); 
fileID=fopen('/Users/Rithesh/Documents/Learn C++/ASE/AudioSoftwareEng/bin/debug/IIRAudioFileTestResult.txt');
D = textscan(fileID,'%f','Delimiter', '\n', 'CollectOutput', true); 
testee = D{1};

testL = testee(1:2:end);

sumOfDiff( FilterOut, testL );


%% FIR Sine Audio Test
% fileID=fopen('/Users/Rithesh/Documents/Learn C++/ASE/AudioSoftwareEng/bin/debug/FIRAudioFileTestResult.txt'); 

[ readText, readWav, sampleRate] = readfiles('/Users/Rithesh/Desktop/test samples/sine_50', 1 );

FilterOut = FIRCombFilter( readWav, 0.01, 1.0, sampleRate );

sumOfDiff( FilterOut, readText );

%% IIR Sine Audio Test
% fileID=fopen('/Users/Rithesh/Documents/Learn C++/ASE/AudioSoftwareEng/bin/debug/FIRAudioFileTestResult.txt'); 
[ readText, readWav, sampleRate] = readfiles('/Users/Rithesh/Desktop/test samples/sine_50', 1 );  

FilterOut = IIRCombFilter( readWav, 0.02, 0.8, sampleRate );

sumOfDiff( FilterOut, readText );
