//Classification: #default/n/IVO/IVV/aA/D(A(v))/fr/ln
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>

int func(int* a) 
{
	int b;
	return a[3] + b;
}

int main(void) 
{
	int a[5]={1,2,3,4,5};
	scanf("%d",&a[3]);
	a[3] = func(a);
	printf("%d ",a[3]); 
	return 0;
}
