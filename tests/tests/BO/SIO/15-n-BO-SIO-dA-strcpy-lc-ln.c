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
	buf1 = (char*)malloc(sizeof(char)*5);
	buf2 = (char*)malloc(sizeof(char)*7);
	if ( (buf1 == 0)||(buf2 == 0) ) { return 1; }
	
	buf1[0]='a';
	buf1[1]='b';
	buf1[2]='c';
	buf1[3]='d';
	buf1[4]='\0';
	
	buf2[0]='a';
	buf2[1]='b';
	buf2[2]='c';
	buf2[3]='d';
	buf2[4]='e';
	buf2[3]='f';
	buf2[4]='\0';
	
	printf ("%s\n", buf1);	
	strcpy (buf1, buf2);
	
	printf ("%s\n", buf1);	
	
	free(buf1);
	free(buf2);
	return 0;
}
