//Classification: #default/p/IVO/IVV/aS/A(v)/lc/rpd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>

int main(void) 
{
	int a;
	int i;
	int c;
	for(a=0,i=0;(i<5)&&(a>-1);a++,i++) {
		c = a;
		printf("%d ",c+a+i);
	}
	return 0;
}
