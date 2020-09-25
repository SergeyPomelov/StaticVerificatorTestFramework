//Classification: #specific_error/n/IVO/IVP/aS/ui_memory/lc/ln
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment: free null pointer

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int *p, a = 10;
	free(p);
	
	p = &a;
	printf ("%d", *p);
	
	return 0;
}
