//Classification: n/BO/UVI/aA/D(v,v)/lc/cd
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include<stdio.h>
#include<string.h>

int main(void) 
{ 
	int i = 1;
	char si[10];
	char so[10];
	char *sh;
	sh=gets(si);
	if (sh==NULL) {
		return 1;
	}
	if (strlen(si)<10) { 
		i = sscanf(si,"%s",so);
		if (i==1) {
			printf("\n%s %d\n",so,i); 
		}
	} else { 
		printf("Error"); 
		return 1;
	}
	return 0;
}
