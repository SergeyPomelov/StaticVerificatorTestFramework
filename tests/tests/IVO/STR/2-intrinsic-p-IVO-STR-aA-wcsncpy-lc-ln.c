//Classification: #intrinsic/p/IVO/STR/aA/wcsncpy/lc/ln
//Written by: Sergey Pomelov
//Reviewed by: 

#include <stdlib.h>
#include <STRar.h>

int main(void)
{
	STRar_t str1[4] = L"abc";
	STRar_t str2[4] = L"abc";
	return *wcsncpy(str2, str1, 2);
}
