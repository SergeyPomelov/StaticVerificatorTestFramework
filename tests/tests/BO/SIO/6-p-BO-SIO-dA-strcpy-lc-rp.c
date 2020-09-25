//Classification: #intrinsic/p/BO/SIO/dA/strcpy/lc/rp
//Written by: Igor Eremeev
//Reviewed by: Pomelov Sergey
//Comment: buffer overflow using strcpy

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (void)
{
	char *buf1, *buf2;
	int i;
	buf1 = (char*)malloc(sizeof(char)*50);
	buf2 = (char*)malloc(sizeof(char)*70);
	if ( (buf1 == 0)||(buf2 == 0) ) { return 1; }
	
	
	for (i = 0; i<49; i++)
	{
		buf1[i]='a'+i;
	}
	buf1[49] = '\0';
	
	for (i = 0; i<39; i++)
	{
		buf2[i]='a'+i;
	}
	buf1[39] = '\0';

	printf ("%s\n", buf1);	
	strcpy (buf1, buf2);
	
	printf ("%s\n", buf1);	
	
	free(buf1);
	free(buf2);
	return 0;
}
