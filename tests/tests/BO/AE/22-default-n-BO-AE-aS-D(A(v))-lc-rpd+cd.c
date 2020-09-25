//Classification: #default/n/BO/AE/aS/D(A(v))/lc/rpd+cd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment: if b!=0 error

#include <stdio.h>

int main(void) 
{
	int a[32];
	int b;
	int i;
	int c;
	scanf("%d",&b);
	for(c=0,i=0;(i<17)&&(c<17);c++,i++) {
		if (b==0) {
			a[b+c+i] = 2*i;
			printf("%d",a[b+c+i]);			
		} else {
			a[i] = i; 
			printf("%d",a[i]);
		}
	}
	return 0;
}
