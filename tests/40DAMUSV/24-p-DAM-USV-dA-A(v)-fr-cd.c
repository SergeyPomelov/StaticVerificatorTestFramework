//Classification: p/DAM/USV/dA/A(v)/fr/cd
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include <stdio.h>
#include <malloc.h>

int *func(void) 
{
	int* q;
	if ((q=(int*)malloc(100*sizeof(	int)))==NULL) {
		printf("malloc error"); 
		return NULL;
	} else {
		return q;
	}
}

int main(void) 
{
	int c;
	scanf("%d",&c);
	int* p = &c;
	if (c<1)
		p = func();
	*(p+c) = 1;
	free(p);
	printf("%d",c);
	return 0;
}
