//Classification: #default/n/BO/PWF/aA/none/lc/ln
//Written by: Igor Eremeev
//Reviewed by: Pomelov Sergey
//Comment:  'printf' operator used without format string

#include <stdlib.h>
#include <stdio.h>

int main (void)
{
	char buf[255];
	fgets (buf, 255, stdin);
	printf (buf);
	return 0;
}
