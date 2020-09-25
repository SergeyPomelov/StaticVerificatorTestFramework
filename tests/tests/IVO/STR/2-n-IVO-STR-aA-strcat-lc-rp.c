//Classification: #intrinsic/n/IVO/STR/aA/strcat/lc/rp
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment:  using not terminated string

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str1[50], str2[100];
	int i;
	str2[0]='\0';
	
	for (i=0; i<=10; i++) {
		str1[i]='a'+i;
	}
	
	strcat(str2, str1);

	printf("%s", str2);
	
	return 0;
}
