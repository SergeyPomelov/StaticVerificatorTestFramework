//Classification: #format_error/n/IVO/FM/aS+aA/scanf/int/string
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment:

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	char c[31];
	char buf[5] = "%d";
	scanf (buf, &c);
	printf("%c",c[0]);
	return 0;
}
