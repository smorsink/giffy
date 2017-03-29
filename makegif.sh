#!/bin/bash

# Script to create rotating star gifs

times
base="/Users/sharon/Dropbox/code/Brock"


# Edit consts.h for:

# Change M to get different M/R values
# M is actually the value of M/R (since R=1)

# Change w to get a different angular velocity, c=3e8
# v/c = w/c  

# Change sdan (in radians) to get angular radius of spot
# Change theta_c (in radians) to get angle for centre of spot

# Change l to switch between intensity or doppler

make all

## MAKING THE DATA FILE
if test ! -d "out"
   	then mkdir -p "out"
fi
if test ! -d "out/newt"
   	then mkdir -p "out/newt"
fi
./newt
gnuplot < out/newtout.plt
#times

./spec
./schw