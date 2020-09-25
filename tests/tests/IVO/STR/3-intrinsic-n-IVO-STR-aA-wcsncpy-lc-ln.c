//Classification: #intrinsic/n/IVO/STR/aA/wcsncpy/lc/ln
//Written by: Sergey Pomelov
//Reviewed by: 
//Comment:  using not terminated string

#include <stdlib.h>
#include <STRar.h>

int main(void)
{
	STRar_t str1[4];
	STRar_t str2[4] = L"abc";
	str1[0]=L'a';
	str1[1]=L'b';
	str1[2]=L'c';
	return *wcsncpy(str2, str1, 3);
}
