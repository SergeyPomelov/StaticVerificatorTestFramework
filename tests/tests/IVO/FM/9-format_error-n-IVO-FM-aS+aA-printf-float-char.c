//Classification: #format_error/n/IVO/FM/aS+aA/printf/float/char
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment:

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	char c = 'a';
	const char buf[5] = "%f";
	printf (buf, c);
	return 0;
}
