//Classification: p/DAM/USV/dS/A(v)/fr/rp+cd
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
		return q;
	}
}

int main(void) 
{
	int c = 1;
	int j;
	int* p = &c;
		for (j=1;j<100;j++)
			if (c==1)
				if (p!=NULL) {
					p = func();
					*p = j;
					free(p);
				}
	printf("%d",c);
return 0;
}
