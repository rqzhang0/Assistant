

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

//#define __debug_zolotarev__

#ifdef __debug_zolotarev__
#ifdef __QMP__
#define print0 if(Layout::primaryNode()) printf
#else
#define print0 printf
#endif  
#else
#define print0 if(1==0) printf
#endif

struct zolotarev_coef_pair
{
      double q;
      double c;
};

class zolotarev_coef : public std::vector<zolotarev_coef_pair>
{
public:
      double ellipticK(double rk);
      void sncndn(double u,double rk,double *sn,double *cn,double *dn);
      
      //Calculate the error with given polynomial order n in the range [lmin, lmax]
      double compute_delta(double lmin, double lmax, int n)
      {
        double delta;
           
        return delta;
      }

      //Calculate the polynomial order needed for given residual goal err
      int get_order(double lmin, double lmax, double err)
      {
        int n=1; 
        while(compute_delta(lmin, lmax, n) > err) n++;
        return n;
      }

      //Calculate the coefficients with given polynomial order n in the range [lmin, lmax]. 
      //  The overall factor should be included in q.
      void compute_coef(double lmin, double lmax, int n)
      {
         
      }

      //Calculate the sign function of y
      double sign(double y)
      {
	for(i=0;i<size();i++)
		result+=(data()[i].q/(y*y+data()[i].c));
	return y*result;
      }
      
      zolotarev_coef:zolotarev_coef(double lmin, double lmax, double err)
      {
        int size = get_order(lmin, lmax, err);
        resize(size);
        compute_coef(lmin, lmax, size);

        print0("--------------------------------------------\n");
        for(int i=0; i<size; ++i) printf("c[%d]=%20.15e  q[%d]=%20.15e\n",i, sqrt(data()[i].c),i, data()[i].q);
        print0("\nlmin: %.15e lmax: %g error: %.2e order: %d\n", lmin, lmax, delta,size);
        print0("--------------------------------------------\n\n");
        print0("y			y/sqrt(y^2)		|1-|y/sqrt(y^2)||\n");
        double y;
        for(y=lmin/2;y<lmax;y*=1.1)
        {
    	  double result=sign(y);
    	  print0("%20.15e %20.15e %20.15e\n",y,result,fabs(1.0-result));
        }
     }
};

