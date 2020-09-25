//Classification: #format_error/n/IVO/FM/aS/scanf/float/char
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment:

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	char c;
	scanf ("%f", &c);
	printf ("%c", c);
	return 0;
}
