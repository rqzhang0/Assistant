#include <stdio.h>
#include "Afc_header.h"

void output_gpu(char **tokens,char **const_array,int j6,int j4,int m6){
	//if((j6==0)&(j4==0)){
	//	printf("%s",tokens[0]);
	//}
	
	 if(j6==0){
		printf("[%s*%s+",tokens[0],const_array[j6]);
	}else if(j6==(m6-1)){
		printf("%s*%s]",tokens[j6],const_array[j6]);
	}else{
		printf("%s*%s+",tokens[j6],const_array[j6]);
	}

}

