//Classification: #intrinsic/n/IVO/STR/aA/strcpy/lc/ln
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment:  using not terminated string

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	char str1[50], str2[50];
	str1[0]='a';
	
	strcpy(str2, str1);

	printf("%s", str2);
	
	return 0;
}
