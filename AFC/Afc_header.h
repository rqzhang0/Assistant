#ifndef Afc_header
#define Afc_header
				
char **convert_split(char *line_in,const char *DELIM,int* n);
char **readline(FILE *filename);
void output_gpu(char **tokens,char **const_array,int j6,int j4,int m6);


#endif
