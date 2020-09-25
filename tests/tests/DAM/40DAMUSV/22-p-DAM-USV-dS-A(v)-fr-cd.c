//Classification: #default/p/DAM/USV/dS/A(v)/fr/cd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>
#include <malloc.h>

int *func(void) 
{
	int* q;
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
	int* p;
	scanf("%d",&c);

	if (c<1){
		p = func();
	} else {
		p = func();
	}
	if (p!=NULL) {
		*p = 1;
		printf("%d", *p);
		free(p);
	}
	printf("%d",c);
	return 0;
}
