//Classification: #default/p/BO/PWF/dS/v/fr/ln
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>

typedef void (*vPtr)(const char *str);
 
void proc(const char *str) 
{
    printf("%s", str);
}
 
int main(int argc, char *argv[])
{
	vPtr func = &proc;
	if (argc > 1) {
	    func(argv[1]);
	}
	return 0;
}
