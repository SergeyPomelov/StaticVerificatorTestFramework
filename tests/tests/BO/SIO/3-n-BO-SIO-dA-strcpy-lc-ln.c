//Classification: #intrinsic/n/BO/SIO/dA/strcpy/lc/ln
//Written by: Igor Eremeev
//Reviewed by: Pomelov Sergey
//Comment: buffer overflow using strcpy

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (void)
{
	char *buf1, *buf2;
	buf1 = (char*)malloc(sizeof(char)*50);
	buf2 = (char*)malloc(sizeof(char)*70);
	if ( (buf1 == 0)||(buf2 == 0) ) { return 1; }
	
	fgets (buf1, 50, stdin);
	fflush(stdin);
	fgets (buf2, 70, stdin);
	printf ("%s\n", buf1);	
	strcpy (buf1, buf2);
	
	printf ("%s\n", buf1);	
	
	free(buf1);
	free(buf2);
	return 0;
}
