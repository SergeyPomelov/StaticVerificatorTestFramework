//Classification: #default/n/ML/UPO/dA/none/lc/cd
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment: if a > 10,  malloc has a closing 'free'; otherwise we don't free it

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int *p[3], a;
	
	scanf ("%d", &a);
	
	p[1] = (int *)malloc(sizeof(int));
	if (p[1]==0) {
		return 1;
	}
	
	if ( a > 10 ) {
		*p[1] = 2345;
		printf ("%d", *p[1]);
		free (p[1]);
	}
	
	p[1] = &a;
	
	printf ("%d", *p[1]);
	return 0;
}
