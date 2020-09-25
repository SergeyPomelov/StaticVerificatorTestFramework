//Classification: #specific_error/n/IVO/IVH/none/uninit_handler/lc/ln
//Written by: Igor Eremeev
//Reviewed by: Pomelov Sergey
//Comment:  using f without fopen

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	FILE* f;
	fprintf (f, "abcdef");
		
	return 0;
}
