//Classification: #default/p/DAM/USV/dA/A(v)/fp/rp+cd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
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
			if (c==j) {
				p = func(p);
				if (p!=NULL) {
					*(p+j) = 1;
					printf ("%d", *(p+j));
					free(p);
				}
			}
	printf("%d",c);
	return 0;
}
