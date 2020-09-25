//Classification: #specific_error/n/IVO/IVH/aA+aS/mode_mismatch/lc/cd
//Written by: Igor Eremeev
//Reviewed by: Pomelov Sergey
//Comment:  write with 'r' mode in one branch

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	char buf[256] = "asdfghjkl", mode[5];
	FILE* f;
	int a;
	
	scanf ("%d", &a);
	
	if (a>10) {
		strcpy (mode,"r");
	}
	else {
		strcpy (mode,"w");
	}
	
	f = fopen ("dat.dat", mode);
	if (f == NULL) { return 1; }
		
	fprintf (f, "%s", buf);
		
	fclose(f);
	return 0;
}
