//Classification: #intrinsic/p/BO/SIO/aA/strlen/lc/rp
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
	
	strcpy (buf, "blablablablablablablablablablablablabla");
	
	a = strlen(buf);
	
	for(i = 0; i<a; i++) {
		A[i] = i;
	}
	
	printf ("%d\n", A[a-1]);
	printf ("%s\n", buf);
	
	return 0;
}
