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
	for (i=0; i<=9; i++) 
		buf[i] = i;
	
	fwrite (buf, sizeof(int), 20, stdin);
	
	return 0;
}
