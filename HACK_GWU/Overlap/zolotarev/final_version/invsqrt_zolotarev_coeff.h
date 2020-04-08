#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <vector>

#ifdef __QMP__
#define print0 if(Layout::primaryNode()) printf
#else
#define print0 printf
#endif  

struct zolotarev_coef_pair
{
      double q;
      double c;
};

class zolotarev_coef : public std::vector<zolotarev_coef_pair>
{
	double A;
public:

 	
	double rf(double xn, double yn, double zn){
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
	
	double ellipticK(double rk)
	{
		double k=rk/sqrt(1+rk*rk);
		if((k<0)||(k>=1)){
			print0("Error ellipticK : k should in [0,1).\n");
			exit(EXIT_FAILURE);
		}
		double Ek;
		Ek=rf(0.0,1.0-(k*k),1.0);
		return Ek;
	}
/*	
	void sncndn(double u, double rk, double *sn, double *cn, double *dn)
	{
	//input paramter u, rk
	//return sn(u,k^2), cn(u,k^2), dn(u,k^2)
	//k=rk/sqrt(1+rk*rk)
		const double Ea=1.0e-15;
		double a,kt,ut,tmp,dn_tmp;
		int size=20;
		double em[size],en[size];
		int i,j,n;
		
		kt=1-rk*rk/(1+rk*rk);
		if(kt<0||kt>=1){
			print0("Error sncndn: k^2 should be in range [0,1)\n");
			exit(EXIT_FAILURE);
		}
		
		ut=u;
		a=1.0;
		*dn=1.0;
		for (i=1;i<size;i++) {
			n=i;
		  	em[i]=a;
		  	en[i]=sqrt(kt);
		  	if(fabs(em[i]-en[i])<=Ea*em[i])
		  		break;
			
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
		   		if(j==n)
		  			*dn=(en[j]+a*tmp*tmp)/(em[j]+a*tmp*tmp);
		   		else
		   			*dn=(en[j]+a*a*tmp*tmp/em[j+1])/(em[j]+a*a*tmp*tmp/em[j+1]);
		     		tmp*=dn_tmp;
		
		   	}
		   	tmp=a*tmp;
		   	a=1.0/sqrt(tmp*tmp+1.0);
		   	if(*sn>=0.0)
		     		*sn=a;
		   	else
		   		*sn=-a;
		   	
		   	*cn=tmp*(*sn);
		}
	
	}
*/

	void sncndn(double u,double rk,double *sn,double *cn,double *dn)
	{
	 int n,flip;
	 double k,kp,K,delta,cd,sd,nd;
	 double sgn_sn=1.0;
	 double sgn_cn=1.0;

         if (rk<0.0)
           {
            printf("Error: sncndn:argument rk is out of range\n");
            (*sn)=0.0;
            (*cn)=1.0;
            (*dn)=0.0;

           exit(EXIT_FAILURE);
	    }

          if (u<0.0)
          {
              u=-u;
              sgn_sn*=-1.0;
          }

         n=((int)(u/ellipticK(rk)))%4;
         u-=(double)((int)(u/ellipticK(rk)))*K;

         switch(n){
           case 1:
                  u=ellipticK(rk)-u;
                  sgn_cn*=-1.0;

          case 2:
                  sgn_sn*=-1.0;
                  sgn_cn*=-1.0;

         case 3:
                  u=ellipticK(rk)-u;
                  sgn_sn*=-1.0;

        }

       if ((2.0*u)<=ellipticK(rk))
       {
          flip=0;
       }else{
        u=ellipticK(rk)-u;
        flip=1;
        }

    kp=1.0/sqrt(1.0+rk*rk);
     k=rk*kp;
		
   delta=pow(DBL_EPSILON,0.125);
    if (delta>1.0e-3)
      delta=1.0e-3;
	      
     if (fabs(u)<delta)
    {
      double u2=u*u;
      double m=k*k;
     (*sn)=u*(1.0-(1.0+m)/6.0*u2+(1.0+14.0*m+m*m)/120.0*u2*u2-(1.0+135.0*m*(1.0+m)+m*m*m)/5040.0*u2*u2*u2);
     (*cn)=sqrt(1.0-(*sn)*(*sn));
    }
    else{
      int nn;
      double kk,kd;
      double D;
					  
      D=sqrt(DBL_EPSILON);
      kd=1.0/sqrt(1.0+rk*rk);
      kk=rk*kd;
				
      for (nn=0;kk>D;nn++)
     {
       u*=(0.5+0.5*kd);
       kk=(kk*kk)/((1.0+kd)*(1.0+kd));
       kd=(2.0*sqrt(kd))/(1.0+kd);
      }
				  
   double m=(kk/kd)*(kk/kd)/(1.0+(kk/kd)*(kk/kd));
   (*sn)=sin(u)-0.25*m*(u-sin(u)*cos(u))*cos(u);
   (*cn)=cos(u)-0.25*m*(u-sin(u)*cos(u))*sin(u);
				      
   for (;nn>0;nn--)
   {

    double fact=1.0/(1.0+kk*(*sn)*(*sn));
   (*sn)=(1.0+kk)*(*sn)*fact;
   (*cn)=(*cn)*sqrt(kd*kd+kk*kk*(*cn)*(*cn))*fact;

   kd=(kd*kd)/((1.0+kk)*(1.0+kk));
   kk=(2.0*sqrt(kk))/(1.0+kk);

    }

  }
   (*dn)=sqrt(kp*kp+k*k*(*cn)*(*cn));

  if (flip==1)
  {
    cd=(*cn)/(*dn);
    sd=(*sn)/(*dn);
    nd=1.0/(*dn);

   (*sn)=cd;
   (*cn)=kp*sd;
   (*dn)=kp*nd;

 }

  (*sn)*=sgn_sn;
  (*cn)*=sgn_cn;
}


	
	double compute_delta(double lmin, int n)
	{
		double eps=lmin*lmin;
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
	
	double sign(double y)
	{
		double result = 0;
		for(int i=0; i<size(); i++)
			result+=(data()[i].q/(y*y+data()[i].c));
			
		return y*A*(1.0+result);
	}
	
      	zolotarev_coef(double lmin, double err, bool print=false)
	{
		//Firstly, compute the polynomial order needed for given residual goal err
		int n=1;
		while(compute_delta(lmin,n)>err && n<200){
			n++;
		}
		resize(n);
	
		if(n==200)
			print0("zolotarev_ceoff ERROR: error %.5e is still larger than the goal %.5e with order 200\n", compute_delta(lmin,n),err);
		
		std::vector<double> ar(2*n);
		std::vector<double> SN(2*n);
		A = 0.0; 
	
		//Firstly, compute all the ars
		double eps=pow(lmin,2);
		double k = sqrt(1.0-eps);
		double rk=k/sqrt(eps);
		double v= ellipticK(rk)/(2.0*n+1);
		
		int r;
		for(r=0;r<2*n; r++){
			double sn, cn, dn;
			sncndn((r+1)*v,rk,&sn,&cn,&dn);
			SN[r]=sn*sn;
			ar[r]=(cn*cn)/(sn*sn);
		}	
		
		//compute c;
		for (r=0; r<n; r++)
			data()[r].c=ar[2*r+1];
	
		//compute bn
		for (r=0;r<n;r++){
			int k;
			data()[r].q=1.0;
			for(k=0;k<n;k++){
				if(r!= k)
					data()[r].q*=(ar[2*k]-ar[2*r+1])/(ar[2*k+1]-ar[2*r+1]);
				else
					data()[r].q*=(ar[2*k]-ar[2*r+1]);
			}
		}
	
		//compute A
		double d = k;
		for(r=0;r<n;r++){
			double sn,cn,dn;
			double cr=SN[2*r];
			d*=k*k*cr*cr;
		}
	
		A= 2.0/(1.0+sqrt(1.0-d*d));
		for(r=0;r<n;r++){
			A*=(SN[2*r]/SN[2*r+1]);
		}

	   if(print==true)
	   {
		print0("A=%f\n",A);
		for(int i=0; i<size(); ++i) print0("c[%d]=%20.15e  q[%d]=%20.15e\n",i, sqrt(data()[i].c),i, data()[i].q);
		print0("--------------------------------------------\n");
		print0("\nlmin: %.15e error: %.2e order: %lu\n", lmin, err ,size());
		print0("--------------------------------------------\n\n");
		print0("y                       y/sqrt(y^2)             |1-|y/sqrt(y^2)||\n");
		for(double y=lmin*0.8; y<1.2; y=y*1.1){
			double result=sign(y);
			print0("%20.15e %20.15f %20.15e\n",y,result,fabs(1.0-result));
		}
           }
	}
	
};
