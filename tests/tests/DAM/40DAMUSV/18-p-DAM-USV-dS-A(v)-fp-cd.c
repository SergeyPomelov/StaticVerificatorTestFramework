//Classification: #default/p/DAM/USV/dS/A(v)/fp/cd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>
#include <malloc.h>

int *func(int *q) 
{
	if ((q=(int*)malloc(sizeof(int)))==NULL) {
		printf("malloc error"); 
		return NULL;
	} else {
		return q;
	}
}

int main(void) 
{
	int a = 1;
	int c;
	int* p = &c;
	scanf("%d",&c);

	if (p!=NULL)
		if ((a=c*2)<1) {
			p = func(p);
			if (p!=NULL){
				*p = 1;
				printf("%d", *p);
				free(p);
			}
		}
	printf("%d %d",c, a);
	return 0;
}
