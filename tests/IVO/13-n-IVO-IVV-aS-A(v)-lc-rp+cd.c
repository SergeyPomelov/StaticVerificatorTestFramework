//Classification: n/IVO/IVV/aS/A(v)/lc/rp+cd
//Written by: Sergey Pomelov
//Reviewed by:
//Comment: if input b>0 in circle no error

#include <stdio.h>

int main(void) 
{
	int a;
	int b;
	int i;
	scanf("%d",&b);
	for(i=1;i<32;i++) {
		if (b<i) {
			printf("%d ",a+i*2);
		} else {
			a = b+i;
			printf("%d ",a);
		}
	}
	return 0;
}
