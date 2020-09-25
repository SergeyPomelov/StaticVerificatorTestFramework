//Classification: p/IVO/IVV/aA/D(A(v))/fr/rp
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include <stdio.h>

int func(int a[]) 
{
	int i;
	for(i=0;i<32;i++) {
		*(a+i) = i;
	}
	return *a;
}

int main(void) 
{
	int a[32];
	int i;
	a[1] = func(a);
	for(i=0;i<32;i++){
		printf("%d ",a[i]); 
	}
	scanf("%d",&a[31]);
	return 0;
}
