//This file compute the colorvector that was need by distillation

#include "qdp.h"
#include <stdio.h>
#include <stdlib.h>

using namespace QDP;

int main(int argc, char *argv[])
{
	QDP_initialize(&argc,&argv);

	const int foo[] = {12,12,12,128};
	multi1d<int> nrow(Nd);

	nrow = foo;

	Layout::setLattSize(nrow);
	Layout::create();

	printf("HELLO, this is the test!\n");

	QDP_finalize();
	
	exit(0);
}
