#include "invsqrt_zolotarev_coeff.h"

double zolotarev_coef::rf(double xn, double yn, double zn){
  double un=(xn+yn+zn)/3.0;
  double Xn=1-xn/un;
  double Yn=1-yn/un;
  double Zn=1-zn/un;
  double Et=0.0025;
  double Ln,RF,E2,E3;
  while(((Et<fabs(Xn))||(Et<fabs(Yn)))||(Et<fabs(Zn))){
  Ln=sqrt(xn*yn)+sqrt(xn*zn)+sqrt(yn*zn);
  xn=(xn+Ln)/4.0;
  yn=(yn+Ln)/4.0;
  zn=(zn+Ln)/4.0;
  un=(xn+yn+zn)/3.0;
  Xn=1-xn/un;
  Yn=1-yn/un;
  Zn=1-zn/un;
  }

  E2=Xn*Yn-Zn*Zn;
  E3=Xn*Yn*Zn;
  RF=((1-0.1*E2+(1.0/14.0)*E3+(1.0/24.0)*E2*E2-(3.0/44.0)*E2*E3)/sqrt(un));
  return RF;


}

double zolotarev_coef::ellipticK(double rk)
{
   double k=rk/sqrt(1+rk*rk);
   if((k<0)||(k>=1)){
   printf("Error ellipticK : k should in [0,1).\n");
   exit(EXIT_FAILURE);
   }
   double Ek;
   Ek=rf(0.0,1.0-(k*k),1.0);
   return Ek;

}

void zolotarev_coef::sncndn(double u, double rk, double *sn, double *cn, double *dn)
{
//input paramter u, rk
//return sn(u,k^2), cn(u,k^2), dn(u,k^2)
//k=rk/sqrt(1+rk*rk)

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

double zolotarev_coef::compute_delta(double lmin, double lmax, int n)
{
	double eps=(lmin/lmax)*(lmin/lmax);
	double k=sqrt(1.0-eps);
	double k_p=sqrt(eps);
	double rk=k/k_p;
	double v=ellipticK(rk)/(2.0*n+1);
	double d=k;
	double delta=1;
	int r;
	
	for (r=1; r<=n; r++){
		double sn,cn,dn;
		sncndn((2*r-1.0)*v,rk,&sn,&cn,&dn);
		double cr=sn*sn;
		d*=k*k*cr*cr;
	}

	delta=d*d/((1.0+sqrt(1-d*d))*(1.0+sqrt(1-d*d)));
	
	return delta;

}

int zolotarev_coef::sign(double y, double *c, double *q, int n, double A)
{
	double result = 0;
	int i = 0;

	for(i=1; i<=n; i++){
		result+=(q[i]/(y*y+c[i]));

	}

	printf("%20.15e %20.15e %20.15e\n",y,y*A*(1.0+result),fabs(1.0-fabs(y*A*(1.0+result))));

	return 0;
}

void zolotarev_coef::compute_zolotarev_coef(double lmin, double lmax, double err)
{
	//Firstly, compute the polynomial order needed for given residual goal err
	int n=1;
	

	while(compute_delta(lmin,lmax,n)>err){
		n++;
	}

	printf("size=%d\n",n);

	if(compute_delta(lmin,lmax,n)>err){
		printf("zolotarev_ceoff ERROR: computed delta larger than err\n");
		printf("delta=%f err=%f\n",compute_delta(lmin,lmax,n),err);
	}
	
	double *ar=(double *) malloc(sizeof(double)*2*n+1);//zolotarev coefficients ar
	double *bn =(double *) malloc(sizeof(double)*n+1);//zolotarev coefficients bn
	double *c =(double *) malloc(sizeof(double)*n+1);
	double *SN = (double *)malloc(sizeof(double)*2*n+1);//to store sn^2
	double A = 0.0; //amplitude A	

	//struct zolotarev_coef_pair coeff[n+1];
	//Firstly, compute all the ars
	double eps=(lmin/lmax)*(lmin/lmax);
	double k = sqrt(1.0-eps);
	double rk=k/sqrt(eps);
	double v= ellipticK(rk)/(2.0*n+1);
	
	printf("v=%f\n",v);

	int r;
	
	for(r=1;r<=2*n; r++){
		double sn, cn, dn;
		sncndn(r*v,rk,&sn,&cn,&dn);
		SN[r]=sn*sn;
		ar[r]=(cn*cn)/(sn*sn);
	}	
	
	//compute c;
	for (r=1; r<=n; r++){
		c[r]=ar[2*r];
	}

	//compute bn
	for (r=1;r<=n;r++){
		int k;
		bn[r]=0;
		double tmp=1.0;
		for(k=1;k<=n;k++){
			if(r!= k){
				tmp*=(ar[2*k-1]-ar[2*r])/(ar[2*k]-ar[2*r]);
			}else{
				tmp*=(ar[2*k-1]-ar[2*r]);
			}
		}
		
		bn[r]=tmp;
	}

	//compute A
	double d = k;
	for(r=1;r<n+1;r++){
		double sn,cn,dn;
		double cr=SN[2*r-1];
		printf("sn^2=%f\n",cr);
		d*=k*k*cr*cr;
	}
	printf("d=%f\n",d);

	 A= 2.0/(1.0+sqrt(1.0-d*d));
	for(r=1;r<=n;r++){
		A*=(SN[2*r-1]/SN[2*r]);
		printf("r=%d A=%f\n",r,A);
	}
	
	printf("A=%f\n",A);
	for (r=1;r<=n;r++){
		printf("c[%d]=%f  bn[%d]=%f \n",r,sqrt(c[r]),r,bn[r]);
	}

	// test sign function
	double y;
	for(y=-1.0; y<1.0; y=y+0.1)
	{
		sign(y,c,bn,n,A);
	}

	//copy data to struct 
	
}

