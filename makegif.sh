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

## Create the directory structure if it doesn't already exist
if test ! -d "out"
   	then mkdir -p "out"
fi
if test ! -d "out/newt"
   	then mkdir -p "out/newt"
fi
if test ! -d "out/spec"
   	then mkdir -p "out/spec"
fi
if test ! -d "out/schw"
   	then mkdir -p "out/schw"
fi

# Create the Newtonian Star Files
./newt
# Gnuplot creates the Newtonian gif
gnuplot < out/newtout.plt

# Create the Special Relativistic Files
./spec
gnuplot < out/specout.plt

#Create the Schwarzschild+Doppler Files
./schw
gnuplot < out/schwout.plt