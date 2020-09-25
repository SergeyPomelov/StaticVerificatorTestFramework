//Classification: #intrinsic/n/IVO/STR/dS/wcslen/lc/ln
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include <stdlib.h>
#include <STRar.h>

unsigned int main(void) 
{
	STRar_t str[10];
	str[1]=L'a';
	str[2]=L'b';
	str[3]=L'c';
    return wcslen(str);
}
