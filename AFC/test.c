#include <stdio.h>
#include <stdlib.h>
#include "Afc_header.h"

int main(int argc, char **argv){

	if(argc!= 2){
		printf("AFC usage: COMMAND <FILENAME>\n");
		exit(EXIT_FAILURE);
	}
	FILE *fp;
	fp=fopen(argv[1],"r");
	char **file_in=readline(fp);
	int i=0;
	while(file_in[i]!=NULL)	
	{
		//printf("i=%d \n",i);
		convert_line_cpu(file_in[i]);	
		i++;

	}

	return 0;
}
