//Classification: #default/n/BO/UVI/aA/v/lc/cd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include<stdio.h>


int main(void) 
{ 
	FILE *in, *out;
	char s[9];
	if((in=fopen("in.txt","rt"))==NULL){
		fprintf(stderr,"Cannot open input file.\n"); 
		return 1;
	}
	if((out=fopen("out.txt","wt"))==NULL){
		fprintf(stderr,"Cannot open output file.\n"); 
		return 1;
	}
	if (!feof(in) && fgets(s,10,in)!=NULL){ 
		fputs(fgets(s,10,in),out);
	}
	return 0;
}
