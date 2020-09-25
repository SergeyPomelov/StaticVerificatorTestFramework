//Classification: #default/p/IVO/IVV/aA/D(A(v))/lc/rpd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>

int main(void) 
{
	int c[32];
	int i;
	int a;
	for(c[0]=0,i=1;(i<5)&&(c[0]>-1);c[0]++,i++) {
		*(c+i)=i;
		printf("%d ",*(c+i));
	}
	return 0;
}
