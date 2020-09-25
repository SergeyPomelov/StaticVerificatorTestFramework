//Classification: #default/p/DAM/USV/dA/A(v)/lc/cd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>
#include <malloc.h>

int main(void) 
{
	const int size = 64;
	int *p;
	int a;
	int c;
	p = (int*)malloc(size*sizeof(int));
		if (p==NULL) {
			printf("alloc error");
			return 1;
		}
	scanf("%d",&c);	
		*(p+30) = 1;
			if ((a=c*2)==10) {	
				printf("%d %d",a,*(p+30));
			} else {
				printf("x %d %d",a,*(p+30));	
			}
	free(p);
	return 0;
}
