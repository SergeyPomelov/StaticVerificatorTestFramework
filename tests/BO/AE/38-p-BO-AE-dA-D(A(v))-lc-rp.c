//Classification: p/BO/AE/aS/D(A(v))/lc/rp
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include <stdio.h>
#include <malloc.h>

int main(void) 
{
	float* a;
	int i;
	if((a = (float*)malloc(32*sizeof(float)))==NULL) {
		printf("malloc error");	
		return 1;
	}
	for(i=0;i<32;i++) {
			a[i] = i; 
	}
	printf("%f",a[31]);
	free(a);
	return 0;
}
