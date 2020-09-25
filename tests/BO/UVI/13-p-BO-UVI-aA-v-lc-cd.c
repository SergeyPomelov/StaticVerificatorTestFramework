//Classification: p/BO/UVI/aA/v/lc/cd
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include<stdio.h>


int main(void) 
{ 
	FILE *in, *out;
	char s[10];
	if((in=fopen("in.txt","rt"))==NULL){
		fprintf(stderr,"Cannot open input file.\n"); 
		return 1;
	}
	if((out=fopen("out.txt","wt"))==NULL){
		fprintf(stderr,"Cannot open output file.\n"); 
		return 1;
	}
	if (!feof(in) && fgets(s,10,in)!=NULL){
		fputs(s,out);
	}
	return 0;
}
