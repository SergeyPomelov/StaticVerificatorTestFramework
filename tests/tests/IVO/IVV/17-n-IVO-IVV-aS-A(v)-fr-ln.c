//Classification: #default/n/IVO/IVV/aA/D(A(v))/fr/ln
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>

int func(int a) 
{
	int b;
	return a + b;
}

int main(void) 
{
	int a;
	scanf("%d",&a);
	a = func(a);
	printf("%d ",a); 
	return 0;
}
