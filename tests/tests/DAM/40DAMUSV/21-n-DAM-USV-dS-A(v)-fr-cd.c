//Classification: #default/n/DAM/USV/dS/A(v)/fr/cd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
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
		free(q);  
		return q;
	}
}

int main(void) 
{
	int c;
	int* p = &c;
	scanf("%d",&c);

	if (c<1)
		p = func();
	*p = 1;
	printf("%d",c);
	return 0;
}
