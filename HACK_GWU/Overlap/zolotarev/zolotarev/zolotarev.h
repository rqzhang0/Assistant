#ifndef zolotarev_header

#define zolotarev_header

double ellipticK(double rk);
void sncndn(double u,double rk,double *sn,double *cn,double *dn);

double compute_delta(double lmin, double lmax, int n);
double compute_coef(double lmin, double lmax, int n, double* q, double*cc);



int zolotarev_coef(double lmin, double lmax, double err,int size);
int sign(double y,double*c, double *q,int size,double A);
#endif
