//Classification: #default/n/BO/AE/aS/D(A(v))/lc/rpd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment: 

#include <stdio.h>

int main(void) 
{
	float a[32];
	int b;
	int i;
	scanf("%d",&b);
	for(a[1]=0,i=0;(i<5)&&(a[1]>-1);a[1]++,i++) {
		if(b==0) {
			a[b+i] = i*2.2;
			printf("%f",a[b+i]);			
		}
	}
	return 0;
}
