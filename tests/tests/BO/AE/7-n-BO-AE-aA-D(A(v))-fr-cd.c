//Classification: #default/n/BO/AE/aA/D(A(v))/fr/cd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>

int func(int a)
{
	a = a - 1;
	return a;
}

int main(void) 
{
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	int i;
	int c = 11;
	if (c>=1 && c<=11 ) {
		c = func(c);
		printf("%d ",a[c]);
	}
	return 0;
}
