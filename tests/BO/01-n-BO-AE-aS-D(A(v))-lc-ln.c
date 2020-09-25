//Classification: n/BO/AE/aS/D(A(v))/lc/ln
//Written by: Pomelov Sergey
//Reviewed by:
//Comment:

#include <stdio.h>

int main()
{
	int x[3] = {1,2,3};
	int *p = x;
	char *c = (char *)(p + 1);
    *c = 'A';
	printf ("%c",*c);
	return 0;
}
