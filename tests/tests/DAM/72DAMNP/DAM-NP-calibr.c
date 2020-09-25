//Classification: #default/n/DAM/NP/aS/v/lc/ln
//Written by: Pomelov Sergey
//Reviewed by: Eremeev Igor
//Comment: unrary* directly initalised NULL pointer.

#include <stdio.h>

int main(void) 
{
	int *p = NULL;
	int a;
	a = *p;
	printf("%d",a);
	return 0;
}
