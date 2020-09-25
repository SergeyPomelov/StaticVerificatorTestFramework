//Classification: n/BO/AE/aA/D(A(v))/lc/ln
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include <stdio.h>

int main(void) 
{
	int a[32];
	int b;
	int i = 31;
	scanf("%d",&b);
	a[b+i] = 2*i; 
	printf("%d",a[31]);
	return 0;
}
