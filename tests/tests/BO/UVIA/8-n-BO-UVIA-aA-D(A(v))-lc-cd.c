//Classification: #default/n/BO/UVIA/aA/D(A(v))/lc/cd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>

int main(void) 
{
	int a[32];
	int b;
	int i = 31;
	scanf("%d",&b);
	if (b<=32 && b>=0){
		return 1;
	}
		if (b!=0) {
			a[b+i] = 2*i; 
		} else {
			a[i] = i; 
		}
	printf("%d",a[31]);
	return 0;
}
