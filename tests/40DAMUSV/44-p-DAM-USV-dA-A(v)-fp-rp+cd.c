//Classification: p/DAM/USV/dA/A(v)/fp/rp+cd
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
		return q;
	}
}

int main(void) 
{
	int c = 1;
	int j;
	int* p = &c;
		for (j=1;j<100;j++)
			if (c==j)
				if (func(p)!=NULL) {
					p = func(p);
					*(p+j) = 1;
					free(p);
				}
	printf("%d",c);
	return 0;
}
