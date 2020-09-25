//Classification: #default/n/BO/AE/aA/D(A(v))/fr/cd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>

int func(int a)
{
	int b;
	scanf("%d",&b);
	if (b>0 && b<=1){ 
		return a+b;
	}
	return a;
}

int main(void) 
{
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	int i;
	int c = 7;
	c = func(c);
	if (c>=0 && c<=8 ) {
		c = func(c);
		printf("%d ",a[c]);
	}
	return 0;
}
