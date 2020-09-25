//Classification: #specific_error/p/IVO/IVH/none/flush_error/fpb/ln
//Written by: Igor Eremeev
//Reviewed by: Pomelov Sergey
//Comment:  yes fflush

#include <stdlib.h>
#include <stdio.h>

int func(FILE *f){
	char buf[256];
	
	fflush (f);
	fgets (buf, 100, f);
	printf ("%s", buf);
	
	return 0;
}

int main(void)
{
	FILE * f;
	
	f = fopen ("dat.dat","r+");
	if (f == NULL) { return 1; }

	fputs ("asdfghjkl", f);
	if ( func(f) == 1 ) {return 1;}
	
	fclose (f);
	return 0;
}
