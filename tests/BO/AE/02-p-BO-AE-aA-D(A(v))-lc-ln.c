//Classification: p/BO/AE/aA/D(A(v))/lc/ln
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include <stdio.h>

int main(void) 
{
	float a[32];
	int i = 31;
	a[i] = i; 
	printf("%f",a[31]);
	return 0;
}
