//Classification: #default/n/BO/UVI/aA/D(v)/lc/ln
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
	if (c!=NULL && strlen(c)<10){ 
		printf("TRUE %s",s);
	} else {
		printf("FALSE");
		return 1;
	}
	return 0;
}
