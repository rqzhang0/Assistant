#include <stdio.h>
#include <math.h>
#include "zolotarev.h"

int main(int argc, char *argv[]){
	double i;
	for(i=0;i<10;i++){
	printf("ellipticK(%f)=%e\n",i,ellipticK(i));
	}	
	

	zolotarev_coef(0.00001,1,2.79e-03);	

	return 0;
}
