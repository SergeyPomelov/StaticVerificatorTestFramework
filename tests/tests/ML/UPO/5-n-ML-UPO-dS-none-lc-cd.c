//Classification: #default/n/ML/UPO/dS/none/lc/cd
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment: if a > 10,  first malloc has a closing 'free'; otherwise we allocate memory twice, but free it only once

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int *p, a;
	
	scanf ("%d", &a);
	
	p = (int *)malloc(sizeof(int));
	if (p==0) {
		return 1;
	}
	
	if ( a > 10 ) {
		(*p) = 2345;
		printf ("%d", *p);
		free (p);
	}
	
	p = &a;	

	printf ("%d", *p);
	
	return 0;
}
