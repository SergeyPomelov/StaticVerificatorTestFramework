//Classification: n/ZD/aS/A(v,c)/lc/rp
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include<stdio.h>

int main(void) 
{
	int a, b, i;
	scanf("%d",&a);
		for (i=1;i<=10;i++) {
			b = 1 / (a - i);	
			printf("%d",b);	
		}
	return 0;
}
