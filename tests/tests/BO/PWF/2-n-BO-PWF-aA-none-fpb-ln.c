//Classification: #default/n/BO/PWF/aA/none/fpb/ln
//Written by: Igor Eremeev
//Reviewed by: Pomelov Sergey
//Comment:  'printf' operator used without format string

#include <stdlib.h>
#include <stdio.h>

int func (char *pc)
{
	printf (pc);
	return 0;
}

int main (void)
{
	char buf[255];
	fgets (buf, 255, stdin);
	if ( func(buf) == 1 ) {return 1;}
	return 0;
}
