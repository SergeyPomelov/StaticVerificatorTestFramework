//Classification: #default/n/DAM/USV/dS/v/lc/rp+cd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>
#include <malloc.h>

int main(void) 
{
	int *p;
	int i;
	int c;
	p = (int*)malloc(sizeof(int));
		if (p==NULL) {
			printf("alloc error");
			return 1;
		}
	*p = 1;
	scanf("%d",&c);	
		for(i=1; i<100; i++) {	
			if (c==i) {	
				free(p);
				printf("%d",*p);
			} else {
				printf("%d",*p);
			}
		}
	free(p);		
	return 0;
}
