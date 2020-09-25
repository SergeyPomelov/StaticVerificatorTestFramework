//Classification: #intrinsic/n/IVO/STR/dA/strcat/lc/rp
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment:  using not terminated string

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	char *str1, str2[100];
	int i;
	str2[0]='\0';
	str1 = (char*)malloc(sizeof(char[50]));
	if (str1 == 0) {
		return 1;
	}
	
	for (i=0; i<=10; i++) {
		str1[i]='a'+i;
	}
	
	strcat(str2, str1);

	printf("%s", str2);
	
	free(str1);
	return 0;
}
