//Classification: #default/n/BO/UVIF/aA/v/lc/ln
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment: 

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int i;
	int buf[10];
	
	fread (buf, sizeof(int), 20, stdin);
	for (i=0; i<=9; i++) 
		printf ("%d\n", buf[i]);
	return 0;
}
