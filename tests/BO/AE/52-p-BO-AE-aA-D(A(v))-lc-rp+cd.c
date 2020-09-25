//Classification: p/BO/AE/aS/D(A(v))/lc/rp+cd
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include <stdio.h>

int main(void) 
{
	int a[32];
	int b;
	int i;
	scanf("%d",&b);
	for(i=0;i<32;i++) {
		if (b==0) {
			a[b+i] = 2*i; 
		} else {
			a[i] = i; 
		}
	}
	printf("%d",a[31]);
	return 0;
}
