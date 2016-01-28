function [ readText, readWav, sampleRate] = readfiles( filesPath, numChannels )

    fileID = fopen( strcat(filesPath,'.txt') ); 
    D = textscan(fileID,'%f','Delimiter', '\n', 'CollectOutput', true); 

    [readWav, sampleRate] = audioread( strcat(filesPath,'.wav') );
    
    readText = D{1};

    % Evaluate Only the left channels if numChannels is greater than two
    if ( numChannels == 2 )
        readText = readText(1:2:end);
        readWav = readWav(:,1);
    end

end