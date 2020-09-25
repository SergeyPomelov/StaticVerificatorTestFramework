//Classification: #default/n/BO/AE/aS/D(A(v))/lc/rpd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment: 

#include <stdio.h>

int main(void) 
{
	int a[32];
	int b;
	int i;
	int c;
	scanf("%d",&b);
	for(c=0,i=0;(i<17)&&(c>-1);c++,i++) {
		if(b==0) {
			a[b+i+c] = 2*i;
			printf("%d",a[b+i+c]);	
		}	
	}
	return 0;
}
