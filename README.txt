/***************************************************************************************************************************************************************
			Neutron Star GIF Maker
			Code written by Brock Moir under supervision of Sharon Morsink (University of Alberta)
***************************************************************************************************************************************************************/

This program is designed to generate an animation of a spot on a neutron star in
 newtonian mechanics (newt.c), special relativistic mechanics (spec.c), and 
 general relativity using the Schwarzchild metric (schw.c).
 
 Units: c=3e8 m/s; radius of the star is dimensionless and set equal to 1
 
 How to Create a gif:
 
 1. Edit parameters in the file include/consts.h
    Change the following parameters:
    M --- ratio of GM/Rc^2
    w --- angular velocity defined so v/c = w/c
    sdan --- angular radius of the spot in radians
    theta_c --- co-latitude of the spot centre (in radians)
    
    For example: The default values are
    M=1.0/10.0 so this means that the compactness is GM/Rc^2 = 0.1
    w=1.0e8 so this means that v/c = 1/3 = 0.3333
    sdan=0.5 so this means the angular radius of the spot is 0.5 radians
    theta_c=pi/4 so this means that the spot centre is 45 degrees from the spin axis
    
 2.    
    
 
 
 
There are a number of additional .h include files associated with each of the 
 options determining the star's mechanics.  These files are located in the 
 /include directory under the file containing the respective name of the
 particular physics involved.

Compilation:
	The Makefile is a template for compilation, depending on your system
	 you may need to edit it somewhat.  The format to generate each exe and
	 execute it is simply make [newt, spec, schw, or all], where all will 
	 generate all the output.

Output:
	Once the make command has been executed, the program will compile and 
	 run.  After the program is finished the useable output can be found in 	 
	the folder /out.  It will contain two outputs for each physical system:
	 the file ending in Fvt.out can be plotted in gnuplot to create a flux
	 vs time graph as the spot completes one full revolution; while the
	 file ending in out.plt must be loaded into gnuplot to generate an
	 animation of the spot revolving around the star.  For example, if I 
	 were to create a spot under special relativistic mechanics, after
	 compilation I would go to the /out folder and begin gnuplot.  At the 
	 gnuplot command line prompt typing plot "specFvt.plt" creates the flux 
	 vs time graph, and typing load "specout.plt" creates the animation.
