//Classification: n/DAM/USV/dA/A(v)/fp/cd
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include <stdio.h>
#include <malloc.h>

int *func(int *q) 
{
	if ((q=(int*)malloc(100*sizeof(int)))==NULL) {
		printf("malloc error"); 
		return NULL;
	} else {
		free(q);  
		return q;
	}
}

int main(void) 
{
	int a = 1;
	int c;
	scanf("%d",&c);
	int* p = &c;
	if (func(p)!=NULL)
		if ((a=c*2)<1)
			p = func(p);
	*(p+c) = 1;
	printf("%d",c);
	return 0;
}
