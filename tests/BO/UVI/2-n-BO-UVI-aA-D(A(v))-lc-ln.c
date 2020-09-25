//Classification: n/BO/UVI/aA/D(A(v))/lc/cd
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include<stdio.h>
#include<string.h>

int main(void) 
{ 
	char s[10];
	char* c;
	c = gets(s);
	if (c!=NULL && strlen(c)<9){ 
		printf("TRUE %s",s);
	} else {
		printf("FALSE");
		return 1;
	}
	return 0;
}
