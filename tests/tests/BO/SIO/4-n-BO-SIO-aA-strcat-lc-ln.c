//Classification: #intrinsic/n/BO/SIO/aA/strcat/lc/ln
//Written by: Igor Eremeev
//Reviewed by: Pomelov Sergey
//Comment: buffer overflow using strcat

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (void)
{
	char buf[30], buf1[40] = "Your string is: ";
	
	fgets (buf, 30, stdin);

	strcat (buf1, buf);
	
	printf ("%s\n", buf1);	
	
	return 0;
}
