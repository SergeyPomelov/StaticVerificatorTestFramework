//Classification: #format_error/n/IVO/FM/aS+aA/scanf/int/float
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment:

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	float c;
	char buf[5] = "%d";
	scanf (buf, &c);
	printf ("%f", c);
	return 0;
}
