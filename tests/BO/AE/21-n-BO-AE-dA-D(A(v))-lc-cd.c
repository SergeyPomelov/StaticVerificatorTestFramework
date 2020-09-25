//Classification: n/BO/AE/dA/D(A(v))/lc/cd
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
	if (b!=0) {
		a[b+i] = i; 
	} else {
		a[i] = i; 
	}
	printf("%f",a[31]);
	free(a);
	return 0;
}
