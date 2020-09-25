//Classification: #default/p/DAM/USV/dA/A(v)/fr/cd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
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
	int* p;
	scanf("%d",&c);

	if (c<1) {
		p = func();
		if (p!=NULL) {
			*(p+c) = 1;
			printf("%d", *(p+c));
			free(p);
		}
	}
	printf("%d",c);
	return 0;
}
