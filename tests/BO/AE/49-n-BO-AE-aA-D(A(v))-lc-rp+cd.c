//Classification: n/BO/AE/aS/D(A(v))/lc/rp+cd
//Written by: Sergey Pomelov
//Reviewed by:
//Comment: if b!=0 error

#include <stdio.h>

int main(void) 
{
	float a[32];
	int b;
	int i;
	scanf("%d",&b);
	for(i=0;i<32;i++) {
		if (b==0) {
			a[b+i] = i; 
		} else {
			a[b] = i; 
		}
	}
	printf("%f",a[31]);
	return 0;
}
