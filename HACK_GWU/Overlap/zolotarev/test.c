#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "zolotarev.h"

int main(int argc, char *argv[]){
	if(argc!=5){
		printf("Error: Usage command lmix lmax error n \n");	
		printf("lmin: the minimum of y\n ");
		printf("lmax: the maximum of y\n");
		printf("error: relative deviation error\n ");
		printf("n: dimension of zolotarev approxmimation\n");
		exit(EXIT_FAILURE);
	}
	printf("argv[1]=%s argv[2]=%s argv[3]=%s argv[4]=%s\n",argv[1],argv[2],argv[3],argv[4]);
	
	int i;
	double delta;

	//vary the value of lmin 
	printf("Vary lmin: \n");
	for(i=0;i<10;i++){
		delta=compute_delta(0.1*pow(0.1,i),1,10);
		printf("%g %g\n",0.1*pow(0.1,i),delta);
		
	}
	
	//vary the dimension of zolotarev approxmimation
	printf("Vary dimension: \n");
	for(i=0;i<10;i++){
		delta=compute_delta(1.0e-05,1,10*i);
		printf("%d %g\n",10*i,delta);
	}



	 delta=compute_delta(atof(argv[1]),atof(argv[2]),atof(argv[4]));	
	printf("TEST: delta=%e\n",delta);
	zolotarev_coef(atof(argv[1]),atof(argv[2]),atof(argv[3]),atof(argv[4]));	

	return 0;
}
