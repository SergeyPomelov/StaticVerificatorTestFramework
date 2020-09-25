//Classification: #default/p/BO/AE/aS/D(A(v))/lc/rpd+cd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>

int main(void) 
{
	float a[32];
	int b;
	int i;
	int c;
	scanf("%d",&b);
	for(c=0,i=0;(i<15)&&(c>-1);c++,i++) {
		if (b==0) {
			a[b+c+i] = i*1.1; 
			printf("%f",a[b+c+i]);	
		} else {
			a[i] = i*1.1;
			printf("%f",a[i]);			
		}
	}
	return 0;
}
