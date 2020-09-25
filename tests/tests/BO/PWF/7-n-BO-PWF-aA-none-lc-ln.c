//Classification: #default/n/BO/PWF/aA/none/lc/ln
//Written by: Igor Eremeev
//Reviewed by: Pomelov Sergey
//Comment:  'printf' operator used without format string

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (void)
{
	char buf[20];
	char fpart[50] = "blablablabla";
	char lpart[15] = "albalbalbalb";
	fgets (buf, 20, stdin);
	
	strcat (fpart, lpart);
	printf (fpart);
	printf ("%s", buf);
	
	return 0;
}
