//Classification: p/BO/AE/aS/D(A(v))/lc/rp
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include <stdio.h>

int main(void) 
{
	float a[32];
	int i;
	for(i=0;i<32;i++) {
			a[i] = i; 
	}
	printf("%f",a[31]);
	return 0;
}
