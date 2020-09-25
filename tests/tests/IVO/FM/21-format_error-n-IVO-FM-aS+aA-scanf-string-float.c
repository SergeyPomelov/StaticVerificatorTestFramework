//Classification: #format_error/n/IVO/FM/aS+aA/scanf/string/float
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment:

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	float c;
	char buf[5] = "%s";
	scanf (buf, &c);
	printf ("%f", c);
	return 0;
}
