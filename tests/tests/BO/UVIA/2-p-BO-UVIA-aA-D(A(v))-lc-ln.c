//Classification: #default/p/BO/UVIA/aA/D(A(v))/lc/ln
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
	if (b<-31 || b>0){
		return 1;
	}
	a[b+i]=i; 
	printf("%d", a[31]);
	return 0;
}
