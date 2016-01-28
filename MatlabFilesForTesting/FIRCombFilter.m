function FilterOut = FIRCombFilter( inputSig, delayInSec, gain, sampleRate ) 

    delLen = sampleRate*delayInSec;

    Delayline = zeros(delLen,1); % memory allocation for length delLen
    FilterOut = zeros(1, length(inputSig));

    for n=1:length(inputSig);

         FilterOut(n)=inputSig(n)+gain*Delayline(delLen);
         Delayline=[inputSig(n);Delayline(1:delLen-1)];

    end;

end
