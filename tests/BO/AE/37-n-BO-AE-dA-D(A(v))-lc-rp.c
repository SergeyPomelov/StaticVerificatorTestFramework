//Classification: n/BO/AE/aS/D(A(v))/lc/rp
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include <stdio.h>
#include <malloc.h>

int main(void) 
{
	float* a;
	int b;
	int i;
	if((a = (float*)malloc(32*sizeof(float)))==NULL) {
		printf("malloc error");	
		return 1;
	}
	scanf("%d",&b);
	for(i=0;i<32;i++) {
		a[b+i] = i; 
	}
	printf("%f",a[31]);
	free(a);
	return 0;
}
