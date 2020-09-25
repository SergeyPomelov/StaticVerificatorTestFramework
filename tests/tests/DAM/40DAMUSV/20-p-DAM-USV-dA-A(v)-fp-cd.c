//Classification: #default/p/DAM/USV/dA/A(v)/fp/cd
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
	int c;
	int* p = &c;
	scanf("%d",&c);

	if (c<1) {
		p = func(p);
		if (p!=NULL) {
			*(p+c) = 1;
			free(p);
		}
	}
	printf("%d",c);
	return 0;
}
