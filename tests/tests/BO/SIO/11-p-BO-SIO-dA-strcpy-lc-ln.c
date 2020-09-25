//Classification: #intrinsic/p/BO/SIO/dA/strcpy/lc/ln
//Written by: Igor Eremeev
//Reviewed by: Pomelov Sergey
//Comment: buffer overflow using strcpy

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (void)
{
	char buf1[50];
	char *s1;

	fgets (buf1, 50, stdin);

	s1 = (char*)malloc(sizeof(char)*(strlen(buf1)+10) );
	if (s1 == 0) { return 1; }
	
	strcpy (s1, buf1);
	
	printf ("%s\n", s1);
	free(s1);
	
	return 0;
}
