//Classification: #default/p/IVO/IVV/aA/D(A(v))/fr/rp+cd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>

int func(int a[]) 
{
	int b;
	int i;
	scanf("%d",&b);
	for(i=0;i<32;i++) {
		if (b<i) {
			*(a+i) = b+i;
		} else {
			*(a+i) = b+i;
		}
	}
	return *a+1;
}

int main(void) 
{
	int a[32];
	int i;
	a[1] = func(a);
	for(i=0;i<32;i++) {
		printf("%d",a[i]); 
	}
	scanf("%d",&a[31]);
	return 0;
}
