//Classification: #default/n/IVO/IVV/aS/A(v)/fr/rp
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>



int func(int a) 
{
	int c;
	int i;
	for(i=0;i<32;i++) {
		a = i;
	}
	return a+c+1;
}

int main(void) 
{
	int a = 1;
	a = func(a);
	printf("%d",a);
	return 0;
}
