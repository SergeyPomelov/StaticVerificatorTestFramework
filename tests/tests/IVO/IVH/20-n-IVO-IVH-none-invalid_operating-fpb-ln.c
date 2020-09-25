//Classification: #specific_error/n/IVO/IVH/none/invalid_operating/fpb/ln
//Written by: Igor Eremeev
//Reviewed by: Pomelov Sergey
//Comment:  assign by value

#include <stdlib.h>
#include <stdio.h>

int func (FILE f) {
	FILE *ff = &f;
	char buf[256];
	
	fgets (buf, 255, ff);
	
	printf ("%s", buf);
	return 0;
}

int main(void)
{
	FILE* f;
	
	f = fopen("dat.dat", "r");
	if (f == NULL) { return 1; }
	
	if ( func(f) == 1 ) {return 1;}
	
	fclose(f);		
	return 0;
}
