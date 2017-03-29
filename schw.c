/***************************************************************************************************************************************************************
        This is the main function to create a newtonian star with a spot 
        of particular properties (as can be defined in const.h.
        There are a number of .h include files that are essential to this 
        program that can be found in the /include file.
        This program itself will generate a number of different outputs.
		in /out
                ==> specout.plt is a file to be loaded into gnuplot to create 
			a .gif animation of the star
                ==> specFvt.plt is a file to be plotted by gnuplot that gives
                        the flux vs time dependance of the spot for one
                        complete revolution.
                in /out/spec all the files are labelled by their time 
                        dependance, the ones begining with an s give the spot's
                        coordinates, while the others give the lines of 
                        latitude and longitude
                                                                                ***************************************************************************************************************************************************************/




#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "include/const.h"
#include "include/schw/rotate.h"
#include "include/schw/schwar.h"
#include "include/schw/spec.h"
#include "include/schw/lolasph.h"
#include "include/schw/sphere.h"

int main(){
int h, i;
double t, dt, tmax, tdelay, b, I_max, v_max, v;
double F, sphi[np+1], cphi[np+1], sthet[np+1], cthet[np+1], dphi, dtheta,
	aalpha[m], apsi[m], cpsimin=1.0, r;
char outname[35];

FILE *out1, *out2;

 printf("Hello! I'm making a rotating star in the Schwarzschild+Doppler Approximation!");

dphi=2.0*pi/((double) np);  
dtheta=2.0*pi/((double) np);

x_y(cphi, sphi, 0, dphi);
x_y_z(sthet, cthet, 0, dtheta);

tmax=1.0;
dt=0.005;
tdelay=200*dt;
v=R*w;
b=1.0/sqrt(1.0-2.0*M/R);
I_max=I_o*CU(sqrt(1.0-SQ(v/c))/((1.0-v/c)*b));
v_max=v_em*sqrt(1.0-SQ(v/c))/((1.0-v/c)*b);
psialp(aalpha, apsi);
for(i=0;i<m;i++){
	if(cpsimin>cos(apsi[i])) cpsimin=cos(apsi[i]), h=i;
}
r=R*sin(aalpha[h])*b;

out1=fopen("out/schwout.plt", "w");
out2=fopen("out/schwFvt.plt", "w");


fprintf(out1, "set term gif animate crop optimize delay %f\n", tdelay);
fprintf(out1, "set output \'schw.gif\'\n");
fprintf(out1, "set pm3d scansforward\n");
fprintf(out1, "set xrange [%f:%f]\n", R*cpsimin, R);
fprintf(out1, "set yrange [-%f:%f]\n", r, r);
fprintf(out1, "set zrange [-%f:%f]\n", r, r);
if(l==0) fprintf(out1, "set cbrange[0:%f]\n", I_max);
else{	fprintf(out1, "set cbrange[0:%f]\n", v_max);
	fprintf(out1, "set palette rgb 10,6,7\n");
}
fprintf(out1, "set size square\n");
fprintf(out1, "set view 90,90\n");
fprintf(out1, "unset xtics\n");
fprintf(out1, "unset ytics\n");
fprintf(out1, "unset ztics\n");
fprintf(out1, "unset title\n");
fprintf(out1, "unset border\n");
fprintf(out1, "unset key\n");

for(t=0; t<tmax; t+=dt){
	fprintf(out1, "splot \"schw/%f.out\" w lines, ", t);
	fprintf(out1, "\"schw/s%f.out\" u 1:2:3:%d w pm3d\n", t, l+4);
	sprintf(outname, "out/schw/s%f.out", t);
	F=schw(outname, (t*2.0*pi/w), aalpha, apsi);
	sprintf(outname, "out/schw/%f.out", t);
	lola(outname, (t*2.0*pi/w), aalpha, apsi, cphi, sphi, cthet, sthet, h);
	fprintf(out2, "%f %f\n", t, F);
	//	printf("%f %f\n", t, F);
}
fprintf(out1, "unset output\n");
fclose(out1);
fclose(out2);

return 0;
}
