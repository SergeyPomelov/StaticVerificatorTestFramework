//Classification: p/DAM/USV/dS/A(v)/fp/rp+cd
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include <stdio.h>
#include <malloc.h>

int *func(	int *q) 
{
	if ((q=(int*)malloc(sizeof(	int)))==NULL) {
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
	int j;
	int* p = &c;
	for (j=1;j<100;j++)
		if (c==j)
			if (func(p)!=NULL) {
				p = func(p);
				*p = 1;
				free(p);
			}
	printf("%d",c);
	return 0;
}
