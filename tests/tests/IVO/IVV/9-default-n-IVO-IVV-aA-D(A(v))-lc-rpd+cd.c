//Classification: #default/n/IVO/IVV/aA/D(A(v))/lc/rpd+cd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment: if input b>=32 in circle no error

#include <stdio.h>

int main(void) 
{
	int a[32];
	int b;
	int i;
	int c;
	scanf("%d",&b);
	for(c=0,i=0;(i<5)&&(c>-1);i++,c++) {
		if (b<i) {
			printf("%d ",*(a+i));
		} else {
			*(a+i) = b+i;
			printf("%d ",*(a+i));
		}
	}
	return 0;
}
