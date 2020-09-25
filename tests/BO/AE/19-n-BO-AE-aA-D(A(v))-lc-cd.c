//Classification: n/BO/AE/aA/D(A(v))/lc/cd
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include <stdio.h>

int main(void) 
{
	int a[32];
	int b;
	int i = 31;
	scanf("%d",&b);
		if (b!=0) {
			a[b+i] = 2*i; 
		} else {
			a[i] = i; 
		}
	printf("%d",a[31]);
	return 0;
}
