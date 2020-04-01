#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void sncndn(double u, double k, double *sn, double *cn, double *dn)
{
	//input parameters u, k^2
	//return sn(u,k^2), cn(u,k^2), dn(u,k^2) 
	const double Ea=1.0e-8;
	double a,kt,ut,tmp;
	double em[14],en[14];
	int i,j,n;

	if(k<0||k>=1){
		printf("Error sncndn: k should be in range [0,1)\n");
		exit(EXIT_FAILURE);
	}	

	kt=1.0-k*k;
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
		//printf("em[i]-en[i]=%f\n",fabs(em[i]-en[i]));
		//printf("a= %f kt=%f\n",a,kt);
		printf("i=%d em=%f en=%f\n",i,em[i],en[i]);
		
	}
	ut *= a;
	*sn=sin(ut);
	*cn=cos(ut);


	//printf("sn=%f cn=%f\n",*sn,*cn);
	if (*sn!=0) {
		tmp=(*cn)/(*sn);
		tmp=tmp;
		//printf("a=%f tmp=%f\n",a,tmp);
		for (j=n;j>=1;j--) {
			if(j==n){
			*dn=(en[j]+a*tmp*tmp)/(em[j]+a*tmp*tmp);
			printf("j=%d tmp=%f\n",j,a*tmp*tmp);
			}else{
			*dn=(en[j]+a*a*tmp*tmp/em[j+1])/(em[j]+a*a*tmp*tmp/em[j+1]);
			printf("j=%d tmp=%f\n",j,a*a*tmp*tmp/em[j+1]);
			//printf("dn = %f \n",*dn);
			//printf("%f\n",en[j]+tmp*tmp/em[j+1]);
			//printf("%f\n",em[j]+tmp*tmp/em[j+1]);
			}
			if(j==1){
				tmp=a*tmp;
				printf("tmp=%f\n",a*tmp);
			}else{
			printf("j=%d tmp=%.20lf\n",j,a*tmp);
			tmp*=(*dn);
			printf("j=%d tmp=%.20lf  dn=%.20lf\n",j,a*tmp,*dn);	
			}	
			
		}
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
	
	sncndn(0.999999,0.99999,&arr[0],&arr[1],&arr[2]);
	printf("%.10lf %.10lf %.10lf\n",arr[0],arr[1],arr[2]);
	
	
	sncndn(0.999999,0.3,&arr[0],&arr[1],&arr[2]);
	printf("%.10lf %.10lf %.10lf\n",arr[0],arr[1],arr[2]);
	

	sncndn(0.3,0.99999,&arr[0],&arr[1],&arr[2]);
	printf("%.10lf %.10lf %.10lf\n",arr[0],arr[1],arr[2]);

	return 0;
}
