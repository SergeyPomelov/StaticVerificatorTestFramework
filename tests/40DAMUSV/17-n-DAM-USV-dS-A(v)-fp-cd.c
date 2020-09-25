//Classification: n/DAM/USV/dS/A(v)/fp/cd
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include <stdio.h>
#include <malloc.h>

int *func(int *q) 
{
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
	int a = 1;
	int c;
	scanf("%d",&c);
	int* p = &c;
	if (func(p)!=NULL)
		if ((a=c*2)<1)
			p = func(p);
	*p = 1;
	printf("%d %d",a,c);
	return 0;
}
