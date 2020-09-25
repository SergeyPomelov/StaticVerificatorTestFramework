//Classification: #specific_error/n/IVO/IVP/aS/non_dynamic/lc/ln
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment: free null pointer

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int a, *p = &a;
	
	(*p) = 10;
	printf ("%d", *p);
	
	free(p);
	return 0;
}
