#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void sncndn(double u, double rk, double *sn, double *cn, double *dn)
{
	//input parameters u, k^2
	//return sn(u,k^2), cn(u,k^2), dn(u,k^2) 
	const double Ea=1.0e-8;
	double a,kt,ut,tmp,dn_tmp;
	double em[14],en[14];
	int i,j,n;

	kt=1-rk*rk/(1+rk*rk);
	if(kt<0||kt>=1){
		printf("Error sncndn: k^2 should be in range [0,1)\n");
		exit(EXIT_FAILURE);
	}	

	ut=u;
	a=1.0;
	*dn=1.0;
	for (i=1;i<=13;i++) {
		n=i;
		em[i]=a;
		en[i]=sqrt(kt);
		if(fabs(em[i]-en[i])<=Ea*em[i]){
			break;
		}
		a=(en[i]+em[i])/2.0;
		kt=en[i]*em[i];
		
	}
	ut *= a;
	*sn=sin(ut);
	*cn=cos(ut);


	if (*sn!=0) {
		tmp=(*cn)/(*sn);
		tmp=tmp;
		for (j=n;j>=1;j--) {
			dn_tmp=*dn;
			if(j==n){
			*dn=(en[j]+a*tmp*tmp)/(em[j]+a*tmp*tmp);
			}else{
			*dn=(en[j]+a*a*tmp*tmp/em[j+1])/(em[j]+a*a*tmp*tmp/em[j+1]);
			}
			{
			tmp*=dn_tmp;
			}	
			
		}
		tmp=a*tmp;
		a=1.0/sqrt(tmp*tmp+1.0);
		if(*sn>=0.0){
			*sn=a;
		}else{
			*sn=-a;
		}
		*cn=tmp*(*sn);
	}
}

int main(void){
	double arr[3];
	int i=0;
	sncndn(0.4,0.5,&arr[0],&arr[1],&arr[2]);
	printf("%.10lf %.10lf %.10lf\n",arr[0],arr[1],arr[2]);

	sncndn(0.001,0.5,&arr[0],&arr[1],&arr[2]);
	printf("%.10lf %.10lf %.10lf\n",arr[0],arr[1],arr[2]);

	sncndn(0.4,0.0001,&arr[0],&arr[1],&arr[2]);
	printf("%.10lf %.10lf %.10lf\n",arr[0],arr[1],arr[2]);
	
	sncndn(0.00000001,0.0000001,&arr[0],&arr[1],&arr[2]);
	printf("%.10lf %.10lf %.10lf\n",arr[0],arr[1],arr[2]);
	
	sncndn(0.00001,0.00001,&arr[0],&arr[1],&arr[2]);
	printf("%.10lf %.10lf %.10lf\n",arr[0],arr[1],arr[2]);
	
	
	sncndn(0.4,0.6*0.6,&arr[0],&arr[1],&arr[2]);
	printf("%.10lf %.10lf %.10lf\n",arr[0],arr[1],arr[2]);
	

	sncndn(0.3,0.99999,&arr[0],&arr[1],&arr[2]);
	printf("%.10lf %.10lf %.10lf\n",arr[0],arr[1],arr[2]);

	return 0;
}
