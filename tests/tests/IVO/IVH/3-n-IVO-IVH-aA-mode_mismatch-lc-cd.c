//Classification: #specific_error/n/IVO/IVH/aA/mode_mismatch/lc/cd
//Written by: Igor Eremeev
//Reviewed by: Pomelov Sergey
//Comment:  write with 'r' mode in one branch

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	char buf[256] = "asdfghjkl";
	FILE* f;
	int a;
	
	scanf ("%d", &a);
	
	if (a>10) {
		f = fopen ("dat.dat", "r");
		if (f == NULL) { return 1; }
	}
	else {
		f = fopen ("dat.dat", "w");
		if (f == NULL) { return 1; }
	}
		
	fprintf (f, "%s", buf);
		
	fclose(f);
	return 0;
}
