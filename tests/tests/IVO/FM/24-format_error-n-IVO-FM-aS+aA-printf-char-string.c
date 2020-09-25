//Classification: #format_error/n/IVO/FM/aS+aA/printf/char/string
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment:

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	char c[] = "fsdgfs";
	const char buf[5] = "%c";
	printf (buf, c);
	return 0;
}
