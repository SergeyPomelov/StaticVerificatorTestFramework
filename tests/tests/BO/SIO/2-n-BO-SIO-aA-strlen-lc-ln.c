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
	
	buf[0] = 'a';
	buf[1] = 'b';
	buf[2] = 'c';
	buf[3] = 'd';
	buf[4] = 'e';
	
	a = strlen(buf);
	A[a] = a;
	
	printf ("%d", A[a]);	
	
	return 0;
}
