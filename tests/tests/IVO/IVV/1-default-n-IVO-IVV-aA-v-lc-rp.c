//Classification: #default/n/IVO/IVV/aA/v/lc/rp
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment: 

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int i;
	int buf[10];
	
	fread (buf, sizeof(int), 5, stdin);
	for (i=0; i<=9; i++) 
		printf ("%d\n", buf[i]);
	return 0;
}
