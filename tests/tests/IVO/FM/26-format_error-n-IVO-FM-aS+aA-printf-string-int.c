//Classification: #format_error/n/IVO/FM/aS+aA/printf/string/int
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment:

#include <stdlib.h>
#include <stdio.h>

int main(void)
{	
	int c = 1234;
	const char buf[5] = "%s";
	printf (buf, c);
	return 0;
}
