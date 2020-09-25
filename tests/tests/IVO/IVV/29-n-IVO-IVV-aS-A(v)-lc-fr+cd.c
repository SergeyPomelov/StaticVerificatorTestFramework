//Classification: #default/n/IVO/IVV/aS/A(v)/fr/rp+cd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment: if input b>0 in circle no error

#include <stdio.h>

int func(int a) 
{
	int b;
	int c;
	int i;
	scanf("%d",&b);
	for(i=0;i<32;i++) {
		if (b<i) {
	        ;
		} else {
			c = a+i;
		}
	}
	return c+1;
}

int main(void) 
{
	int a = 1;
	a = func(a);
	printf("%d",a);
	return 0;
}
