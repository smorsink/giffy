CC = gcc
CFLAGSo = -lm
CFLAGSf = -o

newt: newt.c
	$(CC) $(CFLAGSo) newt.c $(CFLAGSf) newt


spec: spec.c
	$(CC) $(CFLAGSo) spec.c $(CFLAGSf) spec


schw: schw.c
	$(CC) $(CFLAGSo) schw.c $(CFLAGSf) schw

all: 
	$(CC) $(CFLAGSo) schw.c $(CFLAGSf) schw
	$(CC) $(CFLAGSo) spec.c $(CFLAGSf) spec
	$(CC) $(CFLAGSo) newt.c $(CFLAGSf) newt
