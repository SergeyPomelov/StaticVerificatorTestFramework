//Classification: #intrinsic/n/IVO/STR/aA/strcpy/fpb/ln
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment:  using not terminated string

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int func(char *str1) {
	str1[0]='a';
	str1[1]='b';
	str1[2]='c';
	str1[3]='d';
	return 0;
}

int main(void)
{
	char str1[50], str2[50];

	func(str1);
	
	strcpy(str2, str1);

	printf("%s", str2);
	
	return 0;
}
