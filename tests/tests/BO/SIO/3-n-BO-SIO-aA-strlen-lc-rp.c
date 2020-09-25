//Classification: #intrinsic/n/BO/SIO/aA/strlen/lc/rp
//Written by: Igor Eremeev
//Reviewed by: Pomelov Sergey
//Comment: buffer overflow using strlen

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (void)
{
	int A[50], i;
	unsigned int a;
	char buf[100];
	
	for (i = 0; i<30; i++) {
		buf[i] = 'a'+i;
	}
		
	a = strlen(buf);
	A[a] = a;
	
	printf ("%d", A[a]);	
	
	return 0;
}
