//Classification: #default/p/BO/AE/aS/D(A(v))/lc/rpd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>

int main(void) 
{
	float a[32];
	int i;
	int c;
	for(c=0,i=0;(i<15)&&(c>-1);c++,i++) {
			a[i+c] = 0.; 
			printf("%d",a[i+c]);	
	}
	return 0;
}
