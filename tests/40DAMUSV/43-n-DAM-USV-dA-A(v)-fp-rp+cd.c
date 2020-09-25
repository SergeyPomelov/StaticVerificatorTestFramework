//Classification: n/DAM/USV/dA/A(v)/fp/rp+cd
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include <stdio.h>
#include <malloc.h>

int *func(int *q) 
{
	if ((q=(int*)malloc(100*sizeof(	int)))==NULL) {
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
	int j;
	int* p = &c;
	for (j=1;j<100;j++)
		if (func(p)!=NULL) 
			if((a=c*2)==j)
				p = func(p);
	*p = 1;
	printf("%d %d",c,a);
	return 0;
}
