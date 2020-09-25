//Classification: #format_error/n/IVO/FM/aS+aA/printf/string/float
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment:

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	float c = 1234.56;
	const char buf[5] = "%s";
	printf (buf, c);
	return 0;
}
