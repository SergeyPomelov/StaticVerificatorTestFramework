//Classification: #format_error/n/IVO/FM/aS+dA/printf/char/string
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment:

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>

int main(void)
{
	char c[] = "fsdgfs";
	char* pc = (char*)malloc(sizeof(char)*5);
	if (pc == 0) {
		return 1;
	}
	strcpy (pc, "%");
	strcat (pc, "c");
	
	printf (pc, c);
	
	free(pc);
	return 0;
}
