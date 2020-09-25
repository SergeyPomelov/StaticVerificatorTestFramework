//Classification: #default/n/BO/PWF/aA/none/fpb/ln
//Written by: Igor Eremeev
//Reviewed by: Pomelov Sergey
//Comment:  'printf' operator used without format string

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int func (char *pc)
{
	printf (pc);
	return 0;
}

int main (void)
{
	char buf[20];
	char fpart[50] = "blablablabla";
	char lpart[15] = "albalbalbalb";
	fgets (buf, 20, stdin);
	
	strcat (fpart, buf);
	strcat (fpart, lpart);
	
	if ( func(fpart) == 1 ) {return 1;}
	return 0;
}
