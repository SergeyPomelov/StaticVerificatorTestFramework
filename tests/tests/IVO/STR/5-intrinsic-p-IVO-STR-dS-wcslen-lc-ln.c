//Classification: #intrinsic/p/IVO/STR/dS/wcslen/lc/ln
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include <stdio.h>
#include <string.h>
#include <STRar.h>

int main(void) 
{
	STRar_t wideString[] = L"The spazzy orange tiger jumped ? \
	?over the tawny jaguar.";
	wcslen(wideString);
	return 0;
}
