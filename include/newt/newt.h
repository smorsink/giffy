/*******************************************************************************
*	This file is small, but it is here to follow the format of the other   *
*		programs, it determines the intensity of a point as seen by    *
*		an observer.						       *
*******************************************************************************/

double I_em(double alpha){
double I;
//I=I_o*(1.0-0.5*cos(alpha)); // fan beaming
 I=I_o; // Isotropic Emission
return I;
}

