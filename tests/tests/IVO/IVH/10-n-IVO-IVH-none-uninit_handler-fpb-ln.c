//Classification: #specific_error/n/IVO/IVH/none/uninit_handler/fpb/ln
//Written by: Igor Eremeev
//Reviewed by: Pomelov Sergey
//Comment:  using f without fopen

#include <stdlib.h>
#include <stdio.h>

int func(FILE **f) {
	(*f) = fopen("dat.dat", "w");
	if ((*f) == 0) {return 1;}
	
	fprintf (*f, "abcdef");
	fclose (*f);
	
	return 0;
}

int main(void)
{
	FILE* f;
	if (func(&f)==1) {return 1;}
	
	fprintf (f, "abcdef");
	fclose (f);	
	
	return 0;
}
