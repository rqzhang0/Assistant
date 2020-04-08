#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
//#include "invsqrt_chebyshev_coeff.h"
#include "invsqrt_zolotarev_coeff.h"

int main(int argc, char *argv[] ){

    if(argc!=3) { printf("useage: test lower_band order_of_prec\n"); exit(1);}
    double lower_band=atof(argv[1]);
    double residual=pow(0.1,atoi(argv[2]));
    printf("lower_band=%f residual=%f\n",lower_band,residual);
//    chebyshev_coef coef(lower_band, residual,true);
  
    zolotarev_coef coef(lower_band, residual,true);
    
    return 0;
}
