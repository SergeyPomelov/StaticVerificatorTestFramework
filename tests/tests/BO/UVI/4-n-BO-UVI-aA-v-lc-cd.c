//Classification: #default/n/BO/UVI/aA/v/lc/cd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include<stdio.h>
#include<string.h>

int main(void) 
{ 
	char s[10];
	char* c;
	c = gets(s);
	if (c!=NULL){ 
		printf("TRUE %s",s);
	} else {
		printf("FALSE");
		return 1;
	}
	return 0;
}
