//Classification: #intrinsic/n/BO/SIO/aA/strcat/lc/ln
//Written by: Igor Eremeev
//Reviewed by: Pomelov Sergey
//Comment: buffer overflow using strcat

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (void)
{
	char buf[50], buf1[50];
	
	fgets (buf, 26, stdin);
	fflush(stdin);
	fgets (buf1, 26, stdin);
	
	strcat (buf, buf1);
	
	printf ("%s\n", buf);	
	
	return 0;
}
