//Classification: #default/n/BO/PWF/aA/none/lc/ln
//Written by: Igor Eremeev
//Reviewed by: Pomelov Sergey
//Comment:  'printf' operator used without format string

#include <stdlib.h>
#include <stdio.h>

int ex_func (char *pc);

int main (void)
{
	char buf[255];
	if ( ex_func(buf) == 1 ) {return 1;}
	printf (buf);
	return 0;
}
