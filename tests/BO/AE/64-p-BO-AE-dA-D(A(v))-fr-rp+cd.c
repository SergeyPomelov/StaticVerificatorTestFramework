//Classification: p/BO/AE/dA/D(A(v))/fr/rp+cd
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include <stdio.h>
#include <malloc.h>

int *func(int *q) {
    int i;
	int b;
	scanf("%d",&b);
	for(i=0;i<32;i++) {
		if (b==0) {
			q[b+i] = 2*i; 
		} else {
			q[i] = i; 
		}
	}
	return q;
}

int main(void) 
{
	int* a;
	if((a = (int*)malloc(32*sizeof(int)))==NULL) {
		printf("malloc error");	
		return 1;
	}
	printf("%d",*(func(a)+31));
	free(a);
	return 0;
}
