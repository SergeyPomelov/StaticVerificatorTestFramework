//Classification: p/IVO/IVV/aS/A(v)/fr/cd
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include <stdio.h>

int func(int a) 
{
	int b;
	scanf("%d",&b);
	if (b<0) {
	    a = b;
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
