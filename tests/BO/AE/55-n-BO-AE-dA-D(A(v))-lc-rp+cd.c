//Classification: n/BO/AE/aS/D(A(v))/lc/rp+cd
//Written by: Sergey Pomelov
//Reviewed by:
//Comment: b!=0 error

#include <stdio.h>
#include <malloc.h>

int main(void) 
{
	int* a;
	int b;
	int i;
	if((a = (int*)malloc(32*sizeof(int)))==NULL) {
		printf("malloc error");	
		return 1;
	}
	scanf("%d",&b);
	for(i=0;i<32;i++) {
		if (b==0) {
			a[b+i] = 2*i; 
		} else {
			a[b] = i; 
		}
	}
	printf("%d",a[31]);
	free(a);
	return 0;
}
