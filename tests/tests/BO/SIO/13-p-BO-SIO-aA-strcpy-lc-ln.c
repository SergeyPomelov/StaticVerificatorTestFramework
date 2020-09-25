//Classification: #intrinsic/p/BO/SIO/aA/strcpy/lc/ln
//Written by: Igor Eremeev
//Reviewed by: Pomelov Sergey
//Comment: buffer overflow using strcpy

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (void)
{
	char buf1[5], buf2[7];
	
	buf1[0]='a';
	buf1[1]='b';
	buf1[2]='c';
	buf1[3]='d';
	buf1[4]='\0';
	
	buf2[0]='a';
	buf2[1]='b';
	buf2[2]='c';
	buf2[4]='\0';
	
	printf ("%s\n", buf1);	
	strcpy (buf1, buf2);
	
	printf ("%s\n", buf1);	
	
	return 0;
}
