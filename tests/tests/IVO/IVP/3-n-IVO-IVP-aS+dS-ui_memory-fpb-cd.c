//Classification: #specific_error/n/IVO/IVP/aS+dS/ui_memory/fpb/cd
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment: free null pointer

#include <stdlib.h>
#include <stdio.h>



int func (int a, int **p)
{
	if (a>10) {
		*p = (int *)malloc(sizeof(int));
		if (*p == 0) { return 1; }
		
		(**p) = a;
		printf ("%d", **p);
	}
	
	return 0;
}


int main(void)
{
	int *p;
	int a;
	scanf ("%d", &a);
	
	if (func(a, &p) == 1) { return 1; }
	
	free(p);
	return 0;
}
