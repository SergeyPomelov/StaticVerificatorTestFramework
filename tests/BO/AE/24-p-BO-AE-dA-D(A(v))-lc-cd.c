//Classification: p/BO/AE/dA/D(A(v))/lc/cd
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include <stdio.h>
#include <malloc.h>

int main(void) 
{
	int* a;
	int b;
	int i = 31;
	if((a = (int*)malloc(32*sizeof(int)))==NULL) {
		printf("malloc error");	
		return 1;
	}
	scanf("%d",&b);
	if (b==0) {
		a[b+i] = 2*i; 
	} else {
		a[i] = i; 
	}
	printf("%d",a[31]);
	free(a);
	return 0;
}
