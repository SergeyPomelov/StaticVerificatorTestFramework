//Classification: #default/n/DAM/USV/dA/v/lc/rp+cd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>
#include <malloc.h>

int main(void) 
{
	const int size = 64;
	int *p;
	int i;
	int c;
	p = (int*)malloc(size*sizeof(int));
		if (p==NULL) {
			printf("alloc error");
			return 1;
		}
	scanf("%d",&c);	
		for(i=0; i<size; i++) {	
			*(p+i) = 1;
			if (c==i) {	
				free(p);
				printf("%d",*(p+i));
			} else {
				printf("x %d",*(p+i));
				free(p);	
			}
		}
	return 0;
}
