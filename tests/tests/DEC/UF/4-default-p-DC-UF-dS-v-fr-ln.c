//Classification: #default/p/DC/UF/dS/v/fr/ln
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:This test case shows a format string vulnerability in a local control flow; here, we use function pointer for control flow

#include <stdio.h>

typedef void (*vPtr)(const char *str);
 
void proc(const char *str) 
{
    printf("%s", str);
}
 
int main(int argc, char *argv[])
{
    vPtr func = &proc;
    proc(argv[1]);
	func(argv[1]);
	return 0;
}
