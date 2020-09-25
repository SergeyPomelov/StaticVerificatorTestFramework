//Classification: #default/p/DEC/UF/aS/v/fr/cd
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
    int i;    
	scanf("%i",&i);
	
	if (i != 1) {
        vPtr func = &proc;
		func(argv[1]);
	} else {
	proc(argv[1]);
	}
    return 0;
}
