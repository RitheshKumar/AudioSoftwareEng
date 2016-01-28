function sumOfDiff( matlabOut, cppOut )

    sum( abs( matlabOut - cppOut') )
    max( matlabOut - cppOut')

end