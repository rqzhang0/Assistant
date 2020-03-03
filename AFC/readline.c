#include <stdio.h>
#include <stdlib.h>
#include "Afc_header.h"
//**line --> The pointer to [pointer to char]
// So that we can use line[i]=(char *) 

	char **readline(FILE *filename){
		#define step 30
		int bufsize=10;
		char **line=malloc(sizeof(char *)*bufsize);
		char chc;
		int j=0;
		int i=0;
		//printf("i=%d  j=%d\n",i,j);
		do{
			int bufsize_single=100;
			char *single_line=malloc(sizeof(char)*bufsize_single);
			do{
				char ch;
			ch=getc(filename);
			if(ch!='\n'&&ch!=EOF){
				single_line[j]=ch;
				j++;
			}
			chc=ch;
			if(j>=bufsize_single)
               		 {
                	char *single_line_bk=single_line;
                	bufsize_single+=step;
                	single_line=realloc(single_line,sizeof(char)*bufsize_single);
                	if(!single_line){
                		free(single_line_bk);
                		fprintf(stderr,"readline error: allocation error of single_line\n");
				exit(EXIT_FAILURE);
			}
			 }
			}while(chc!='\n'&&chc!=EOF);
			
			if(chc=='\n'){
				single_line[j]='\0';
				line[i]=single_line;
				//printf("line %d  %s \n",i,line[i]);
				i++;
				j=0;
			}
			{
				char **line_bk=line;
				bufsize+=step;
				line=realloc(line,sizeof(char *)*bufsize);
				if(!line){
					free(line);
					fprintf(stderr,"readline error: allocation error of line\n");
					exit(EXIT_FAILURE);
		
				}
			}
		}while(chc != EOF);

		return line;
	}
