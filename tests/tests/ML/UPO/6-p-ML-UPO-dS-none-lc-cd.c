//Classification: #default/p/ML/UPO/dS/none/lc/cd
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment: if a > 10,  both 'malloc's have a closing 'free'; otherwise we have one malloc and one free

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int *p, a;
	
	scanf ("%d", &a);
		
	if ( a > 10 ) {
		p = (int *)malloc(sizeof(int));
		if (p==0) {
			return 1;
		}
	
		(*p) = 2345;
		printf ("%d", *p);
		free (p);
	}
	
	p = (int *)malloc(sizeof(int));
	if (p==0) {
		return 1;
	}
	
	(*p) = 1234;
	printf ("%d", *p);
	free(p);
	
	return 0;
}
