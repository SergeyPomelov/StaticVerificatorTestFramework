//Classification: n/BO/AE/dA/D(A(v))/lc/ln
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include <stdio.h>
#include <malloc.h>

int main(void) 
{
	float* a;
	int b;
	int i = 31;
	if((a = (float*)malloc(32*sizeof(float)))==NULL) {
		printf("malloc error");	
		return 1;
	}
	scanf("%d",&b);
	a[b+i] = i; 
	printf("%f",a[31]);
	free(a);
	return 0;
}
