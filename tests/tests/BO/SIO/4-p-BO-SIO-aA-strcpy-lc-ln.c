//Classification: #intrinsic/p/BO/SIO/aA/strcpy/lc/ln
//Written by: Igor Eremeev
//Reviewed by: Pomelov Sergey
//Comment: buffer overflow using strcpy

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (void)
{
	char buf1[50], buf2[70];
	
	fgets (buf1, 30, stdin);
	fflush(stdin);
	fgets (buf2, 40, stdin);
	printf ("%s\n", buf1);	
	strcpy (buf1, buf2);
	
	printf ("%s\n", buf1);	
	
	return 0;
}
