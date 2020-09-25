//Classification: #intrinsic/n/IVO/STR/dA/strcat/lc/ln
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment:  using not terminated string

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	char *str1, str2[100];
	str2[0]='\0';
	str1 = (char*)malloc(sizeof(char[50]));
	if (str1 == 0) {
		return 1;
	}
	
	str1[0]='a';
	str1[1]='b';
	str1[2]='c';
	str1[3]='d';
	
	strcat(str2, str1);

	printf("%s", str2);
	
	free(str1);
	return 0;
}
