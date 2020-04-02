#include "invsqrt_zolotarev_coeff.h"

int main()
{
	int i;
	zolotarev_coef test;
	printf("TEST complete elliptic integral:\n");
	for(i=0;i<10;i++){
		printf("ellipticK(%f)=%f\n",i/10.0,test.ellipticK(i/10.0));

	}

	printf("TEST Jacobi elliptic function: \n");

	double arr[3];
       test.sncndn(0.4,0.5,&arr[0],&arr[1],&arr[2]);
       printf("%.10lf %.10lf %.10lf\n",arr[0],arr[1],arr[2]);

        test.sncndn(0.001,0.5,&arr[0],&arr[1],&arr[2]);
        printf("%.10lf %.10lf %.10lf\n",arr[0],arr[1],arr[2]);

        test.sncndn(0.4,0.0001,&arr[0],&arr[1],&arr[2]);
        printf("%.10lf %.10lf %.10lf\n",arr[0],arr[1],arr[2]);

        test.sncndn(0.00000001,0.0000001,&arr[0],&arr[1],&arr[2]);
        printf("%.10lf %.10lf %.10lf\n",arr[0],arr[1],arr[2]);

        test.sncndn(0.00001,0.00001,&arr[0],&arr[1],&arr[2]);
        printf("%.10lf %.10lf %.10lf\n",arr[0],arr[1],arr[2]);


        test.sncndn(0.4,0.6*0.6,&arr[0],&arr[1],&arr[2]);
        printf("%.10lf %.10lf %.10lf\n",arr[0],arr[1],arr[2]);


	printf("TEST coefficients:\n");
	
	test.compute_zolotarev_coef(0.1,1,2.47e-12);

	printf("TEST delta:\n");
	double delta = test.compute_delta(0.1,1.0,11);

	printf ("delta = %e\n",delta);


	printf("TEST sign function: \n");
	


	return 0;
}
