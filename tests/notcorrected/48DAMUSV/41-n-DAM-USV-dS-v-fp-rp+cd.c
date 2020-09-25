//Classification: n/DAM/USV/dS/v/fp/rp+cd
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include <stdio.h>
#include <malloc.h>

int *func(int *q) 
{
	if ((q=(int*)malloc(sizeof(int)))==NULL) {
		printf("alloc error"); 
		return NULL;
	} else {
		free(q);  
		return q;
	}
}

int main(void) 
{
	const int size=64;
	int* p;
	int i;
	int c;
	scanf("%d",&c);	
		for(i=0; i<size; i++) {	
			if (c==i) {	
				p = func(p);
				printf("%d",*p);
			} else {
				*p = 1;
				printf("%d",*p);
			}
		}	
	printf("%d",c);
	return 0;
}
