//Classification: #default/p/IVO/IVV/aA/D(A(v))/lc/cd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>

int main(void) 
{
	int a[32];
	int b;
	scanf("%d",&b);
	if (b<0) {
		*(a+16) = 2*b;
		printf("%d ",*(a+16));
	} else {
		*(a+16) = b;
		printf("%d ",*(a+16));
	}
	return 0;
}
