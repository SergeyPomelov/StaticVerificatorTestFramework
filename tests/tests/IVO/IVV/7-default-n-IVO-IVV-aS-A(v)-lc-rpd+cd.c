//Classification: #default/n/IVO/IVV/aS/A(v)/lc/rpd+cd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment: if input b>0 in circle no error

#include <stdio.h>

int main(void) 
{
	int a;
	int b;
	int i;
	scanf("%d",&b);
	for(c=0,i=0;(i<5)&&(c>-1);i++,c++) {
		if (b<i) {
			printf("%d ",a+i*2);
		} else {
			a = b+i;
			printf("%d ",a);
		}
	}
	return 0;
}
