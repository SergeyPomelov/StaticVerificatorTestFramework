//Classification: n/DAM/USV/dA/v/fr/ln
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:
// 1. нет проверки, не вернуло ли func NULL

#include <stdio.h>
#include <malloc.h>

int *func(void) {
	int* q;
	if ((q=(int*)malloc(100*sizeof(int)))==NULL) {
		printf("malloc error"); 
		return NULL;
	}
	else {
		free(q);
		return q;
	}
}

int main(void) {
	int c =1;
	int* p;
	
	p = func();
	if p==NULL return 1;
	*(p+c) = 1;
	printf("%d",c);
	
	return 0;
}
