//Classification: #default/n/BO/UVI/aA/D(v,v)/lc/ln
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include<stdio.h>

int main(void) 
{ 
	int i;
	char si[10];
	char so[10];
	scanf("%s",si);
	i = sscanf(si,"%s",so);
	printf("\n%s %d\n",so,i);
	return 0;
}
