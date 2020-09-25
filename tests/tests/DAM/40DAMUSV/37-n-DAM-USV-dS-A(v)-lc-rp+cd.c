//Classification: #default/n/DAM/USV/dS/A(v)/lc/rp+cd
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
	int a;
	int c;
	p = (int*)malloc(sizeof(int));
		if (p==NULL) {
			printf("alloc error");
			return 1;
		}
	scanf("%d",&c);	
		for(i=0; i<size; i++) {	
			*p = 1;
			if ((a=c*2)==i) {	
				free(p);
				printf("%d %d",a,*p);
				return 0;
			} else {
				printf("x %d %d",a,*p);
			}
		}
	free(p);	
	return 0;
}
