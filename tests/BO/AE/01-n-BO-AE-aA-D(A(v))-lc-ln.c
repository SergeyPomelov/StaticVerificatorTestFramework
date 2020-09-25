//Classification: n/BO/AE/aA/D(A(v))/lc/ln
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include <stdio.h>

int main(void) 
{
	float a[32];
	int b;
	int i = 31;
	scanf("%d",&b);
	a[b+i] = i; 
	printf("%f",a[31]);
	return 0;
}
