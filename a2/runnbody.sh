#!/bin/bash

echo "Exploring Raspberry Pi Chapter 5 Performance Test Code"
echo "By Derek Molloy, using code from benchmarksgame.alioth.debian.org"
echo "Please see the source files for the author details."
echo "All source code has been edited to remove proccessor specific optimizations"
echo "Running the Tests:"
echo "*** Please ensure that you do not have the ondemand governor enabled ***"

Duration="5000000"

echo -e "\nThe C/C++ Code Example"
T="$(date +%s%N)"
./n-body $Duration
T="$(($(date +%s%N)-T))"
T=$((T/1000000))
echo "It took ${T} milliseconds to run the C/C++ test"

echo -e "\nThe C++11 Code Example"
T="$(date +%s%N)"
./n-body2 $Duration
T="$(($(date +%s%N)-T))"
T=$((T/1000000))
echo "It took ${T} milliseconds to run the C++11 test"

echo "Finished Running the Benchmarks"