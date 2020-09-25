//Classification: #intrinsic/n/BO/SIO/aA/strcat/fpb/rp
//Written by: Igor Eremeev
//Reviewed by: Pomelov Sergey
//Comment: buffer overflow using strcat; printing abc

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int getAlfU (char *pc, int i)
{
	pc[0] = 'A'+i;
	pc[1] = '\0';
	return 0;
}


int getAlfL (char *pc, int i)
{
	pc[0] = 'a'+i;
	pc[1] = '\0';
	return 0;
}


int main (void)
{
	char str[58]="ABC is: ", buf[5];
	int i;
	
	for (i=0; i<26; i++) {
		getAlfU(buf, i);
		strcat (str, buf);
		getAlfL(buf, i);
		strcat (str, buf);
	}
	
	printf ("%s\n", str);	
	
	return 0;
}
