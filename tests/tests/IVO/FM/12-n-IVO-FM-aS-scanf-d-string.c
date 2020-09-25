//Classification: #format_error/n/IVO/FM/aS/scanf/int/string
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment:

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	char c[31];
	scanf ("%d", &c);
	printf("%c",c[0]);
	return 0;
}
