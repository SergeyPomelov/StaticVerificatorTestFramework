//Classification: #intrinsic/n/BO/SIO/aA/strcat/lc/rp
//Written by: Igor Eremeev
//Reviewed by: Pomelov Sergey
//Comment: buffer overflow using strcat

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (void)
{
	char buf[50]= "sdlkjfsdkjhfksdjhf";
	char bbuf[1000];
	int i;
	
	for (i = 0; i<999; i++) {
		bbuf[i] = 'a';
	}
	bbuf[999]='\0';
	
	strcat (buf, bbuf);
	
	printf ("%s\n", buf);	
	
	return 0;
}
