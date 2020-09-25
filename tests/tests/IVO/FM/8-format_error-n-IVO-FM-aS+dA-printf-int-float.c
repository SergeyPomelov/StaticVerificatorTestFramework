//Classification: #format_error/n/IVO/FM/aS+dA/printf/int/float
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment:

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>

int main(void)
{
	float c = 1234.56;
	char* pc = (char*)malloc(sizeof(char)*5);
	if (pc == 0) {
		return 1;
	}
	strcpy (pc, "%");
	strcat (pc, "d");
	
	printf (pc, c);
	
	free(pc);
	return 0;
}
