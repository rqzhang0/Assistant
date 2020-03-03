#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Afc_header.h"

int main(int argc, char **argv)
{
	if(argc != 2){
		printf("AFC usage: COMMAND <FILENAME>\n");
		exit(EXIT_FAILURE);

	}
	FILE *fp;
	fp=fopen(argv[1],"r");
	char **file_in=readline(fp);
	//char test_char[]="a=b+c*d";
	const char* DELIM="=";
	int n=0;
	char **line=convert_split(file_in[0],DELIM,&n);
	//printf("%s\n",line[0]);
	//printf("%s\n",line[1]);
	//printf("%d\n",n);
	int i;
	int j;
	int j2;
	int j3;
	int j4;
	int j5;
	int j6;
	for(i=0;i<n;i++){
		int m1=0;
	char **line1=convert_split(line[i],"+",&m1);
		for(j=0;j<m1;j++){
			int m2;
			//printf("%d %s\n",j,line1[j]);
			char **line2=convert_split(line1[j],"-",&m2);
			for(j2=0;j2<m2;j2++){
				int m3;
				//printf("%d %s\n",j2,line2[j2]);
				char **line3=convert_split(line2[j2],"*",&m3);
				for(j3=0;j3<m3;j3++){
					int m4;
					//printf("%d %s\n",j3,line3[j3]);
					char **line4=convert_split(line3[j3],"[",&m4);
					for(j4=0;j4<m4;j4++){
						int m5;
						//printf("%d %s \n",j4,line4[j4]);
						char **line5=convert_split(line4[j4],"]",&m5);
						for(j5=0;j5<m5;j5++){
						int m6;
						//printf("%d %s \n",j5,line5[j5]);
						char **line6=convert_split(line5[j5],",",&m6);
						for(j6=0;j6<m6;j6++){
							//printf("%d %s\n",j6,line6[j6]);
							if((j6==0)&(j4==0)){
								printf("%s",line6[0]);
							}else{
								printf("[%s]",line6[j6]);
							}

						}		
						}
					}
				}
			}
		}
	}
	printf(";\n");
	return 0;
}
