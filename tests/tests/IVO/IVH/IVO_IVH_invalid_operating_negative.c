//Classification: #specific_error/n/IVO/IVH/none/invalid_operating/lc/ln
//Written by: Igor Eremeev
//Reviewed by: Pomelov Sergey
//Comment:  assign by value

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	char buf[256];
	FILE* f;
	FILE* qf;
	
	f = fopen ("dat.dat", "r");
	if (f == NULL) { return 1; }
	qf = (FILE*)malloc(sizeof(FILE));
	if (qf == 0) { return 1; }

	(*qf) = (*f);
		
	fgets (buf, 255, qf);
	printf ("%s", buf);

	free (qf);	
	fclose(f);

	return 0;
}
