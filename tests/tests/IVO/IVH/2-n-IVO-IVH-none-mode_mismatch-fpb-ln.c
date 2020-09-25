//Classification: #specific_error/n/IVO/IVH/none/mode_mismatch/fpb/ln
//Written by: Igor Eremeev
//Reviewed by: Pomelov Sergey
//Comment: write with 'r' mode 

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int func(FILE *f){
	fclose (f);

	f = fopen ("dat.dat", "r");
	if (f == NULL) { return 1; }
	return 0;
}

int main(void)
{
	char buf[256] = "asdfghjkl";
	FILE* f;
	
	f = fopen ("dat.dat", "w");
	if (f == NULL) { return 1; }
	fprintf (f, "%s", buf);
	
	if (func(f) == 1) {return 1;}
	strcpy (buf, "eflkjsdjkfh");
	fprintf (f, "%s", buf);
		
	fclose(f);
	return 0;
}
