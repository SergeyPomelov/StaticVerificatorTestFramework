//Classification: n/BO/AE/aA/D(A(v))/lc/cd
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include <stdio.h>

int main(void) 
{
	float a[32];
	int b;
	int i = 31;
	scanf("%d",&b);
		if (b!=0) {
			a[b+i] = i; 
		} else {
			a[i] = i; 
		}
	printf("%f",a[31]);
	return 0;
}
