//Classification: #intrinsic/n/BO/SIO/aA/strcpy/lc/rp
//Written by: Igor Eremeev
//Reviewed by: Pomelov Sergey
//Comment: buffer overflow using strcpy

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (void)
{
	char buf1[50], buf2[70];
	int i;
	
	for (i = 0; i<49; i++)
	{
		buf1[i]='a'+i;
	}
	buf1[49] = '\0';
	
	for (i = 0; i<69; i++)
	{
		buf2[i]='a'+i;
	}
	buf1[69] = '\0';
	
	printf ("%s\n", buf1);	
	strcpy (buf1, buf2);
	
	printf ("%s\n", buf1);	
	
	return 0;
}
