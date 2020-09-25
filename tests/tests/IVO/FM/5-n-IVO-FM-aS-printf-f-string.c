//Classification: #format_error/n/IVO/FM/aS/printf/float/string
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment:

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	char c[] = "fsdgfs";
	printf ("%f", c);
	return 0;
}
