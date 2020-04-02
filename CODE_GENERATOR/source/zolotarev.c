#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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



double ellipticK( double rk)
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

void sncndn(float uu, float emmc, float *sn, float *cn, float *dn )
{
	



}

int main(void){
	double Ek=ellipticK(0.1);
	double Ef=ellipticK(0.2);
	printf("Ek=%f %f\n",Ek,Ef);

	printf("Ek=%f %f\n",ellipticK(0.9));
	printf("Ek=%f %f\n",ellipticK(0.7));
	printf("Ek=%f %f\n",ellipticK(0.5));
	return 0;
}
