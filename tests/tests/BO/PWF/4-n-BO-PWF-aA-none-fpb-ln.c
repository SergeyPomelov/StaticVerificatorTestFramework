//Classification: #default/n/BO/PWF/aA/none/fpb/ln
//Written by: Igor Eremeev
//Reviewed by: Pomelov Sergey
//Comment:  'printf' operator used without format string

#include <stdlib.h>
#include <stdio.h>

int ex_func (char *pc);

int func (char *pc)
{
	printf (pc);
	return 0;
}

int main (void)
{
	char buf[255];
	if ( ex_func(buf) == 1 ) {return 1;}
	func (buf);
	return 0;
}
