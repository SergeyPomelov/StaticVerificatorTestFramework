//Classification: #intrinsic/n/BO/SIO/aA/strlen/lc/ln
//Written by: Igor Eremeev
//Reviewed by: Pomelov Sergey
//Comment: buffer overflow using strlen

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (void)
{
	char buf[5];
	
	buf[0] = 'a';
	buf[1] = 'b';
	buf[2] = 'c';
	buf[3] = 'd';
	
	buf[strlen(buf)] = '\0';

	printf ("%s", buf);
	
	return 0;
}
