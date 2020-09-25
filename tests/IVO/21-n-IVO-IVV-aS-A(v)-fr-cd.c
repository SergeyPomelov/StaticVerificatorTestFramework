//Classification: n/IVO/IVV/aS/A(v)/fr/cd
//Written by: Sergey Pomelov
//Reviewed by:
//Comment: if b<0 error

#include <stdio.h>

int func(int a)
{ 
	int b;
	scanf("%d",&b);
	if (b<0) {
		;
	} else {
		a = b;
	}
	return a+b+1;
}

int main(void) 
{
	int a = 1;
	a = func(a);
	printf("%d",a);
	return 0;
}
