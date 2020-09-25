//Classification: #default/n/BO/UVIA/aA/D(A(v))/lc/ln
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>

int main(void) 
{
	int a[32];
	int b;
	scanf("%d",&b);
	if ( (b>=0) && (b<32)){
		return 1;
	}
	a[b]=123; 
	printf("%d", a[b]);
	return 0;
}
