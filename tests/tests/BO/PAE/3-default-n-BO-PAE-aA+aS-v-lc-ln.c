//Classification: #default/n/BO/PAE/aA+aS/v/lc/ln
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment: 

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	char buf[4];
	long *p = (long*)buf;
	*p = 123456;
	
	printf ("%d", *p);
	
	return 0;
}
