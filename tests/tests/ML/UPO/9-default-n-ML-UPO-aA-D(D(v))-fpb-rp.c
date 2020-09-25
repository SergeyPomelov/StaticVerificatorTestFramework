//Classification: #default/n/ML/UPO/aA/D(D(v))/fpb/rp
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment: 

#include <stdlib.h>
#include <stdio.h>

int func_malloc (int **p)
{
	*p = (int *)malloc(sizeof(int));
	if ((*p)==0) {
		return 1;
	}
	return 0;
}

int main(void)
{
	int *p[10], i;
			
	for (i = 0; i<=9; i++) {
		if ( func_malloc(&p[i]) == 1 ) { return 1; }
		*p[i] = i*10;
		printf ("%d", *p[i]);
	}

	for (i = 0; i<=8; i++) {
		free (p[i]);
	}

	return 0;
}
