//Classification: #default/n/IVO/IVV/aA/D(A(v))/lc/rp
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>

int main(void) 
{
	int a[32];
	int i;
	for(i=1;i<32;i++) {
		printf("%d ",*(a+i));
	}
	return 0;
}
