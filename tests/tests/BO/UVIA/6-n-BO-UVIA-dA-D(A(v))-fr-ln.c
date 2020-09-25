//Classification: #default/n/BO/UVIA/dA/D(A(v))/fr/ln
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>
#include <malloc.h>

int *func(int *q) {
    int b;
    int i = 31;
	scanf("%d",&b);
	if (b<=32 && b>=0){
		return q;
	}
	q[b+i] = 2*i; 
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
