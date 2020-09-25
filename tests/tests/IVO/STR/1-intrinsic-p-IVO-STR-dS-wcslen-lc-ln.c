//Classification: #intrinsic/p/IVO/STR/dS/wcslen/lc/ln
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include <stdlib.h>
#include <STRar.h>

unsigned int main(void) 
{
	STRar_t *wideString = L"abc";
        return wcslen(wideString);
}
