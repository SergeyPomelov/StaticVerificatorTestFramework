//Classification: #intrinsic/n/IVO/STR/aA/strcpy/fpb/rp
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment:  using not terminated string

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int func(char *str1) {
	int i;
	
	for (i=0; i<=10; i++) {
		str1[i]='a'+i;
	}
	
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
