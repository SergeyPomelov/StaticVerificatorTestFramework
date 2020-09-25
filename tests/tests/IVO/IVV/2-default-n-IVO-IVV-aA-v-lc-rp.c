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
	for (i=0; i<=4; i++) 
		buf[i] = i;
	
	fwrite (buf, sizeof(int), 10, stdin);

	return 0;
}
