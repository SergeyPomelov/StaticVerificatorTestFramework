//Classification: n/DAM/USV/dS/A(v)/fr/cd
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include <stdio.h>
#include <malloc.h>

int *func(void) 
{
	int* q;
	if ((q=(int*)malloc(sizeof(int)))==NULL) {
		printf("malloc error"); 
		return NULL;
	} else {
		free(q);  
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
	*p = 1;
	printf("%d",c);
	return 0;
}
