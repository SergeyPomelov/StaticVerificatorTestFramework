//Classification: n/DAM/USV/dA/A(v)/fr/rp+cd
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
		free(q);  
		return q;
	}
}

int main(void) 
{

	int c = 1;
	int j;
	int* p = &c;
		for (j=1;j<100;j++)
			if (p!=NULL) 
				p = func();
	printf("%d",c);
	return 0;
}
