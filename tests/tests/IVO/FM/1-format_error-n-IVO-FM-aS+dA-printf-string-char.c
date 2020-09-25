//Classification: #format_error/n/IVO/FM/aS+dA/printf/string/char
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment: 

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>

int main(void)
{
	char c = 'a';
	char* pc = (char*)malloc(sizeof(char)*5);
	if (pc == 0) {
		return 1;
	}
	strcpy (pc, "%");
	strcat (pc, "s");
	
	printf (pc, c);
	
	free(pc);
	return 0;
}
