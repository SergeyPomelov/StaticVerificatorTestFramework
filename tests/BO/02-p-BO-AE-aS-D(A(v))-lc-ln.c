//Classification: n/BO/AE/aS/D(A(v))/lc/ln
//Written by: Pomelov Sergey
//Reviewed by:
//Comment:

#include <stdio.h>

int main()
{
	int x[3] = {1,2,3};
	int *p = x;
	int *f = (p+1);
    *f = 7;
	printf ("%d",*f);
	return 0;
}
