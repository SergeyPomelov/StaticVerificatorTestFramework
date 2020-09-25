//Classification: p/BO/AE/aS/D(A(v))/lc/rp
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include <stdio.h>
#include <malloc.h>

int main(void) 
{
	int* a;
	int i;
	if((a = (int*)malloc(32*sizeof(int)))==NULL) {
		printf("malloc error");	
		return 1;
	}
	for(i=0;i<32;i++) {
			a[i] = i; 
	}
	printf("%d",a[31]);
	free(a);
	return 0;
}
