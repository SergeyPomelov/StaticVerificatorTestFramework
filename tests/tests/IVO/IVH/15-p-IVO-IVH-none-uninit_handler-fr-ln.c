//Classification: #specific_error/p/IVO/IVH/none/uninit_handler/fr/ln
//Written by: Igor Eremeev
//Reviewed by: Pomelov Sergey
//Comment:  using fopen

#include <stdlib.h>
#include <stdio.h>

FILE* func() {
	FILE* pf;

	pf = fopen("dat.dat", "w");
	if (pf == 0) {return NULL;}

	return pf;
}

int main(void)
{
	FILE* f;
	f = func();
	if (f == NULL) {return 1;}
	
	fprintf (f, "abcdef");
	fclose (f);	
	
	return 0;
}
