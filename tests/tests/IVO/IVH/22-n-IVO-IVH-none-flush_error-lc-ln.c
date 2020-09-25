//Classification: #specific_error/n/IVO/IVH/none/flush_error/lc/ln
//Written by: Igor Eremeev
//Reviewed by: Pomelov Sergey
//Comment:  no fflush

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	FILE * f;
	char buf[256];
	
	f = fopen ("dat.dat","r+");
	if (f == NULL) { return 1; }

	fputs ("asdfghjkl", f);
	
	
	fgets (buf, 100, f);
	printf ("%s", buf);
	fclose (f);

	return 0;
}
