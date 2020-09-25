//Classification: #default/n/BO/AE/aA/D(A(v))/lc/rp+cd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>

int main(void) 
{
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	int i;
	int c;
	scanf("%d",&c);
	if (c<0) {
		c=10;
	} else { 
		c=9;
	}
	for (i=0;i<=c;i++){
		printf("%d ",*(a+i));
	}
}
