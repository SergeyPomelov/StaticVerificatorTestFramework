//Classification: #intrinsic/n/BO/SIO/aA/strlen/lc/ln
//Written by: Igor Eremeev
//Reviewed by: Pomelov Sergey
//Comment: buffer overflow using strlen

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (void)
{
	int A[50];
	unsigned int a;
	char buf[100];
	
	fgets (buf, 100, stdin);
	a = strlen(buf);
	A[a] = a;
	
	printf ("%d", A[a]);	
	
	return 0;
}
