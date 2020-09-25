//Classification: #default/n/IVO/IVV/aA/D(A(v))/fr/cd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:  if b<0 error

#include <stdio.h>

int func(int a[]) 
{
	int b;
	scanf("%d",&b);
	if (b<0) {
		printf("%d ",*(a+16));
	} else {
		*(a+16) = b;
		printf("%d ",*(a+16));
	}
	return 0;
}

int main(void) 
{
	int a[32];
	int i;
	a[1] = func(a);
	printf("%d ",a[16]); 
	scanf("%d",&a[31]);
	printf("%d ",a[31]); 
	return 0;
}
