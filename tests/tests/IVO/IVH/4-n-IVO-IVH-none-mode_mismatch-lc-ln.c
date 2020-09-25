//Classification: #specific_error/n/IVO/IVH/none/mode_mismatch/lc/ln
//Written by: Igor Eremeev
//Reviewed by: Pomelov Sergey
//Comment:  write with 'r' mode

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	char buf[256] = "asdfghjkl";
	FILE* f;
	
	f = fopen ("dat.dat", "w");
	if (f == NULL) { return 1; }
	fprintf (f, "%s", buf);
	fclose (f);
	
	strcpy (buf, "abcde");
	f = fopen ("dat.dat", "r");
	if (f == NULL) { return 1; }
	fprintf (f, "%s", buf);
		
	fclose(f);
	return 0;
}
