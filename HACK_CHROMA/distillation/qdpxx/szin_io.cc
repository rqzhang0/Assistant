//This file compute the colorvector that was need by distillation

#include "qdp.h"
#include <stdio.h>
#include <stdlib.h>


using namespace QDP;

struct SzinGauge_t
{
 //SzinGauge_t();

 int Nd;
 int Nc;

 int TotalTrj;
 int TotalCG;
 int FermTypeP;
 int spec_acc;

 int NOver;
 int TotalTry;
 int TotalFail;
 int Npf;
 int RefMomTrj;
 int RefFnoiseTrj;
 Real32 MesTrj;
 Real32 BetaMC;
 Real32 BetaMD;
 Real32 dt;
 Real32 KappaMC;
 Real32 KappaMD;
 Real32 Nf;
 Real32 LamPl;
 Real32 LamMi;
 Real32 AlpLog;
 Real32 AlpExp;
 QDP::Seed seed;
		  
int cfg_version;
			   
 std::string banner;
 std::string date;
};


int main(int argc, char *argv[])
{
	QDP_initialize(&argc,&argv);

	int Nd=4;	
	const int foo[] = {12,12,12,128};
	multi1d<int> nrow(Nd);

	nrow = foo;

	Layout::setLattSize(nrow);
	Layout::create();

	printf("HELLO, this is the test!\n");
	//Read cfg_file into memory
	std::string cfg_file="test.lime";
	BinaryFileReader cfg_in(cfg_file);
	
	int date_size;
	read(cfg_in,date_size);

	printf("datasize=%d\n",date_size);

	printf("finished read test.lime\n");
	
	SzinGauge_t header;	

	read(cfg_in,header.cfg_version);
	read(cfg_in,header.Nd);

	printf("version=%d\n",header.cfg_version);
	printf("Nd=%d\n",header.Nd);
        

	QDP_finalize();
	
	exit(0);
}
