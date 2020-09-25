//Classification: #format_error/n/IVO/FM/aS+aA/scanf/string/int
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment:

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int c;
	char buf[5] = "%s";
	scanf (buf, &c);
	printf ("%d", c);
	return 0;
}
