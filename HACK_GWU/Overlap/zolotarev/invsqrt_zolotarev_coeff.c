#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "zolotarev.h"

static double compute_delta(double lmin, double lmax, int n)
{
  double eps = pow(lmin/lmax, 2);
  double k = sqrt(1-eps);
  double rk = k/sqrt(eps);

  double K = ellipticK(rk);
  double v = K/(2*n+1);

  double d=1;
  for(int r=1; r<=2*n-1; r+=2)
  {
    double sn, cn, dn;
    sncndn(r*v, rk, &sn, &cn, &dn);
    printf("n=%d r=%d r*v=%e rk=%e sn=%e cn=%e dn=%e \n",n,r,r*v,rk,sn,cn,dn);
    d *= pow(sn, 4);
  }
  //d *= pow(k, 2*n);
  d *= pow(k, 2*n+1);
  //d=7.1938e-02;
  double delta = d*d/pow(1+sqrt(1-d*d), 2);
  //printf("k=%20.15e d=%e delta=%e\n",k,d,delta);
  return delta;
}

static double compute_coef(double lmin, double lmax, int n, double* q, double *cc)
{
  double eps = pow(lmin/lmax, 2);
  double k = sqrt(1-eps);
  double rk = k/sqrt(eps);

  double K = ellipticK(rk);
  double v = K/(2*n+1);

  double *c = (double*)malloc(2*n*sizeof(double));
  double *a = (double*)malloc(2*n*sizeof(double));
  //for(int r=1; r<=2*n-1; ++r)
  for(int r=1; r<=2*n; ++r)
  {
    double sn, cn, dn;
    sncndn(r*v, rk, &sn, &cn, &dn);
    c[r] = sn*sn;
    a[r] = pow(cn/sn,2);
    printf("coefficients: a[%d]=%g\n",r,a[r]);
  }


  double d=1;
  for(int r=1; r<=2*n-1; r+=2) d*=c[r]*c[r];
  //d *= pow(k, 2*n);
  d *= pow(k, 2*n+1);
  //d = 7.1938e-02;
  double delta = d*d/pow(1+sqrt(1-d*d), 2);
  printf("k=%20.15e d=%e delta=%e\n",k,d,delta);

  //double A = (1-delta)/(1+delta);
  double A = 1;
  A *= 2/(1+sqrt(1-d*d));
  //A /= c[1];
  for(int r=1; r<=2*n-1; r+=2) A *= c[r]/c[r+1];

  for(int i=0; i<n; ++i) cc[i] = a[2*i+2];
  for(int i=0; i<n; ++i)
  {
    q[i] = 1;
    //for(int j=0; j<n-1; ++j) q[i] *= (cc[i] - a[2+j*2]);
    for(int j=0; j<n; ++j) q[i] *= (cc[i] - a[j*2+1]);
    for(int j=0; j<n; ++j) if( j != i) q[i] /= (cc[i] - cc[j]);
  }

  for(int i=0; i<n; ++i)
  {
    cc[i] *= 1;
    //q[i] *= A*lmax;
    q[i] *= 1;
  }

  // reverse order
//  for(int i=0, j=n-1; i<j; ++i, --j) 
 // {
  //  double tmp = cc[i]; cc[i] = cc[j]; cc[j] = tmp;
   // tmp = q[i]; q[i] = q[j]; q[j] = tmp;
 // }


  free(c);
  free(a);

  return A;
}

static int get_order(double lmin, double lmax, double delta)
{
  int n=1; 
  while(compute_delta(lmin, lmax, n) > delta) n++;
  return n;
}

int sign(double y,double*c, double *q,int size,double A){
	double result=0; 
	double result1=0;
	int i=0;
//	A=3.91e-01;
//	c[0]=6.4034e-01;
//	c[1]=1.7265e-01;
//	c[2]=5.0201e-02;
//	c[3]=1.4687e-02;
//	c[4]=4.2992e-03;
//	c[5]=1.2585e-03;
//	c[6]=3.6834e-04;
//	c[7]=1.0761e-04;
//	c[8]=3.0777e-05;
//	c[9]=6.5361e-06;

//	q[0]=1.5207e+00;
//	q[1]=3.5041e-01;
//	q[2]=1.0053e-01;
//	q[3]=2.9377e-02;
//	q[4]=8.5984e-03;
//	q[5]=2.5170e-03;
//	q[6]=7.3694e-04;
//	q[7]=2.1615e-04;
//	q[8]=6.4722e-05;
//	q[9]=2.3893e-05;

	for(i=0;i<10;i++){
		printf("%f %f\n",sqrt(c[i]),q[i]);
	}

	for(i=0;i<size;i++){
		result+=((-1)*q[i]/(y*y+c[i]));
		result1+=(q[i]/(y*y+c[i]));
		printf("q[%d]=%e c[i]=%e y=%e result=%20.15e result1=%20.15e\n",i,q[i],sqrt(c[i]),y,result,result1);
	}
	printf("A=%20.15e y=%20.15e result=%20.15e result1=%20.15e\n",A,y,y*A*(1.0+result));
	return 0;
}

int zolotarev_coef(double lmin, double lmax, double err)
{
 int size = get_order(lmin, lmax, err);
 size=10;
 double delta = compute_delta(lmin, lmax, size);
 double* c = malloc(sizeof(double)*size);
 double* q = malloc(sizeof(double)*size);
  double A=compute_coef(lmin, lmax, size, q, c);

  // Print report
 // if(get_node_rank()==0)
  {
    printf("\nZolotarev approximation of order %d\n", size);
    printf("--------------------------------------------\n");
    for(int i=0; i<size; ++i) printf("c[i]=%20.15e  q[i]=%20.15e\n", sqrt(c[i]), q[i]);
    printf("\nlmin: %.15e lmax: %g delta: %.2e\n", lmin, lmax, delta);
    printf("--------------------------------------------\n\n");
  }
  double y=-1;
  for(y=-1;y<1;y=y+0.1)
  {
	sign(y,c,q,size,A);

  }


  return 0;
}


