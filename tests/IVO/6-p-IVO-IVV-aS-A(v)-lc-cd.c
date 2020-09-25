//Classification: p/IVO/IVV/aS/A(v)/lc/cd
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include <stdio.h>

int main(void) 
{
	int a;
	int b;
	scanf("%d",&b);
	if (b<0) {
		a = 2*b;
		printf("%d ",a);
	} else {
		a = b;
		printf("%d ",a);
	}
	return 0;
}
