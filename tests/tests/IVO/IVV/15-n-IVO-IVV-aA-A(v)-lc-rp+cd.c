//Classification: #default/n/IVO/IVV/aA/D(A(v))/lc/rp+cd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment: if input b>=32 in circle no error

#include <stdio.h>

int main(void) 
{
	int a[32];
	int b;
	int i;
	scanf("%d",&b);
	for(i=1;i<32;i++) {
		if (b<i) {
			printf("%d ",*(a+i));
		} else {
			*(a+i) = b+i;
			printf("%d ",*(a+i));
		}
	}
	return 0;
}
