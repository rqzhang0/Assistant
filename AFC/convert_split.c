#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Afc_header.h"
	char **convert_split(char *line_in,const char *DELIM,int* position)
	{
		int bufsize=100;
		*position = 0;
		//printf("position %d\n",*position);
		char **tokens=malloc(sizeof(char*)*bufsize);
		char *token, **tokens_backup;

		if(!tokens){
			fprintf(stderr,"Convert_split: tokens allocation error\n");
			exit(EXIT_FAILURE);
		}
		token = strtok(line_in,DELIM);	
		tokens[*position]=token;
		(*position)++;
		//printf("%s\n",token);
		while(token!=NULL)
		{
			
			if((token=strtok(NULL,DELIM))==NULL)
			{
				//printf("strtok returned NULL, BREAK\n");
				//printf("%d\n",*position);
				break;	
			}else if((strcmp(DELIM,"[")!=0)&(strcmp(DELIM,"]")!=0)&(strcmp(DELIM,",")!=0)){
				//printf("token2 %s",token);
				char *test_token=malloc(sizeof(char)*bufsize);
				strcpy(test_token,DELIM);
				strcat(test_token,token);
				//printf("test_token %s\n",test_token);
				tokens[*position]=test_token;
				(*position)++;
			}else if((strcmp(DELIM,"[")==0)|(strcmp(DELIM,"]")==0)|(strcmp(DELIM,",")==0)){
				tokens[*position]=token;
				(*position)++;	
			}
		

		}
		
		return tokens;
	}
