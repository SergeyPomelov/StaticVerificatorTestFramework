//Classification: #specific_error/n/IVO/IVH/none/mode_mismatch/fr/ln
//Written by: Igor Eremeev
//Reviewed by: Pomelov Sergey
//Comment:  write with 'r' mode

#include <stdlib.h>
#include <stdio.h>

FILE* func(){
	FILE *f;
	f = fopen ("dat.dat", "r");
	if (f == NULL) { return NULL; }
	return f;
}

int main(void)
{
	char buf[256] = "asdfghjkl";
	FILE* f;
	
	f = func();
	if (f == NULL) { return 1; }
		
	fprintf (f, "%s", buf);
		
	fclose(f);
	return 0;
}
