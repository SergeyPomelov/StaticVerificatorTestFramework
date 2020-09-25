//Classification: #intrinsic/n/BO/SIO/aA/strcat/lc/ln
//Written by: Igor Eremeev
//Reviewed by: Pomelov Sergey
//Comment: buffer overflow using strcat

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (void)
{
	char buf[50];
	
	fgets (buf, 40, stdin);
	printf ("%s\n", buf);	
	strcat (buf, "blablablabla");
	
	printf ("%s\n", buf);	
	
	return 0;
}
