#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void sncndn(float u, float k, float *sn, float *cn, float *dn)
{
	//input parameters u, k^2
	//return sn(u,k^2), cn(u,k^2), dn(u,k^2) 
	const double Ea=1.0e-8;
	float a,b,c,kt,ut;
	float em[14],en[14];
	int i,j,n,bo;

	if(k<0||k>=1){
		printf("Error sncndn: k should be in range [0,1)\n");
		exit(EXIT_FAILURE);
	}	

	kt=1-k*k;
	ut=u;
	a=1.0;
	*dn=1.0;
	for (i=1;i<=13;i++) {
		n=i;
		em[i]=a;
		kt=sqrt(kt);
		en[i]=kt;
		c=0.5*(a+kt);
		if(fabs(a-kt)<= Ea*a){
			break;
		}
		kt *= a;
		a=c;
		//a=0.5*(a+kt);
	}
	ut *= c;
	//ut *= a;
	*sn=sin(ut);
	*cn=cos(ut);
	if (*sn!=0) {
		a=(*cn)/(*sn);
		c *= a;
		for (j=n;j>=1;j--) {
			b=em[j];
			a *= c;
			c *= (*dn);
			*dn=(en[j]+a)/(b+a);
			a=c/b;
		}
		a=1.0/sqrt(c*c+1.0);
		*sn=(*sn >= 0.0 ? a : -a);
		*cn=c*(*sn);
	}
}

int main(void){
	float arr[3];
	sncndn(0.4,0.5,&arr[0],&arr[1],&arr[2]);
	printf("%f %f %f\n",arr[0],arr[1],arr[2]);

	return 0;
}
