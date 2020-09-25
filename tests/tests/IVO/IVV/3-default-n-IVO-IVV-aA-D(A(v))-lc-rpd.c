//Classification: #default/n/IVO/IVV/aA/D(A(v))/lc/rpd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>

int main(void) 
{
	int a[32];
	int i;
    int c;
	for(c=0,i=0;(i<5)&&(c>-1);c++,i++) {
		printf("%d ",*(a+i));
	}
	return 0;
}
