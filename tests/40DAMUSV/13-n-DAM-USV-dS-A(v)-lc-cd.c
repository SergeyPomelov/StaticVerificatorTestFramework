//Classification: n/DAM/USV/dS/A(v)/lc/cd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>
#include <malloc.h>

int main(void) 
{
	int *p;
	int a;
	int c;
	p = (int*)malloc(sizeof(int));
		if (p==NULL) {
			printf("alloc error");
			return 1;
		}
	scanf("%d",&c);	
		*p = 1;
			if ((a=c*2)==10) {	
				free(p);
				printf("%d %d",a,*p);
				return 0;
			} else {
				printf("x %d %d",a,*p);
			}
	free(p);	
	return 0;
}
