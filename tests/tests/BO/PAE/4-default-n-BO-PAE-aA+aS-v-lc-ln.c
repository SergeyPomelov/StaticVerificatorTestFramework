//Classification: #default/n/BO/PAE/aA+aS/v/lc/ln
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment: 

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	char buf[4];
	double *p = (double*)buf;
	*p = 123.456;
	
	printf ("%f", *p);
	
	return 0;
}
