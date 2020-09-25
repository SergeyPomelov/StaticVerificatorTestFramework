//Classification: #default/n/BO/PAE/aA+aS/v/lc/ln
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment: 

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	char buf[3];
	int *p = (int*)buf;
	*p = 12345;
	
	printf ("%d", *p);
	
	return 0;
}
