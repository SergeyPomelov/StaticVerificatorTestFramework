//Classification: #intrinsic/n/BO/SIO/aA/strcat/fpb/rp
//Written by: Igor Eremeev
//Reviewed by: Pomelov Sergey
//Comment: buffer overflow using strcat; printing ABC

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int getAlfU (char *pc)
{
	int i;
	for (i=0; i<26; i++) {
		pc[i] = 'A'+i;
	}
	pc[i] = '\0';
	return 0;
}

int getAlfL (char *pc)
{
	int i;
	for (i=0; i<26; i++) {
		pc[i] = 'a'+i;
	}
	pc[i] = '\0';
	return 0;
}


int main (void)
{
	char buf[27], buf1[27];
	
	getAlfU(buf);
	getAlfL(buf1);
	
	strcat (buf, buf1);
	
	printf ("%s\n", buf);	
	
	return 0;
}
