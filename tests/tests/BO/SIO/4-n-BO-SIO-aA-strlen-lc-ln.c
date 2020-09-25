//Classification: #intrinsic/n/BO/SIO/aA/strlen/lc/ln
//Written by: Igor Eremeev
//Reviewed by: Pomelov Sergey
//Comment: buffer overflow using strlen

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (void)
{
	char buf[100];
	
	fgets (buf, 100, stdin);
	buf[strlen(buf)+1] = 'a';
	
	printf ("%s", buf);	
	
	return 0;
}
