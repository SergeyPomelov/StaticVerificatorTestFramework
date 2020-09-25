//Classification: #format_error/n/IVO/FM/aS+aA/scanf/float/char
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment:

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	char c;
	char buf[5] = "%f";
	scanf (buf, &c);
	printf ("%c", c);
	return 0;
}
