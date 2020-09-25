//Classification: p/ZD/aA/A(D(v),c)/fp/ln
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include <stdio.h>

int func(int ar[2]) 
{
	int b = 1;
	b = b / (ar[1] + 1);
	printf("%d",b);
	return b;
}

int main(void) 
{
	int a[2];
	a[0]=0;
	a[1]=0;
	a[0] = func(a);
	return 0;
}
