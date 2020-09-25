//Classification: #default/n/BO/PAE/aA+aS/v/lc/ln
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment: 

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	char buf[7];
	int *p = (int*)buf;
	*p = 12345;
	*(p+1) = 23456;
	
	printf ("%d", *p + *(p+1));
	
	return 0;
}
