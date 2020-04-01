#include <stdio.h>
#include <math.h>

void sncndn(double uu, double emmc, double *sn, double *cn, double *dn)
{
	const double CA=1.0e-8;
	double a,b,c,d,emc,u;
	double em[14],en[14];
	int i,ii,l,bo;

	emc=1-emmc*emmc;
	u=uu;
	if (emc) {
		bo=(emc < 0.0);
		/*if (bo) {
			d=1.0-emc;
			emc /= -1.0/d;
			u *= (d=sqrt(d));
		}*/
		a=1.0;
		*dn=1.0;
		for (i=1;i<=13;i++) {
			l=i;
			em[i]=a;
			en[i]=(emc=sqrt(emc));
			c=0.5*(a+emc);
			if (fabs(a-emc) <= CA*a) break;
			//printf("a-emc=%f\n",fabs(a-emc));
			emc *= a;
			a=c;
			//printf("%a= %f emc=%f\n",a,emc);
			printf("i=%d em=%f en=%f \n",i,em[i],en[i]);
		}
		u *= c;
		*sn=sin(u);
		*cn=cos(u);
		//printf("sn=%f cn=%f\n",*sn,*cn);
		if (*sn) {
			//printf("HE a=%f\n",a);
			a=(*cn)/(*sn);
			c *= a;
			//printf("c=%f \n",c);
			for (ii=l;ii>=1;ii--) {
				b=em[ii];
				a *= c;
				printf("j=%d c=%.20lf\n",ii,c);
				c *= (*dn);
				printf("ii=%d c=%.20lf dn=%.20lf\n",ii,c,*dn);
				*dn=(en[ii]+a)/(b+a);
				printf("dn = %f \n",*dn);
				//printf("%f\n",en[ii]+a);
				//printf("%f\n",b+a);
				printf("j=%d a=%f \n",ii,a);
				a=c/b;
			}
			a=1.0/sqrt(c*c+1.0);
			*sn=(*sn >= 0.0 ? a : -a);
			*cn=c*(*sn);
		}
		/*if (bo) {
			a=(*dn);
			*dn=(*cn);
			*cn=a;
			*sn /= d;
		}*/
	} /*else {
		*cn=1.0/cosh(u);
		*dn=(*cn);
		*sn=tanh(u);
	}
	*/
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

