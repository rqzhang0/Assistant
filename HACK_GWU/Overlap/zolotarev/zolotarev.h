#ifndef zolotarev_header

#define zolotarev_header

double ellipticK(double rk);
void sncndn(double u,double rk,double *sn,double *cn,double *dn);


int zolotarev_coef(double lmin, double lmax, double err);

int sign(double y,double*c, double *q,int size,double A);
#endif
