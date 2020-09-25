//Classification: #specific_error/p/IVO/IVH/none/mode_mismatch/lc/ln
//Written by: Igor Eremeev
//Reviewed by: Pomelov Sergey
//Comment:  create mode string correctly

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	char mode[5], buf[256];
	FILE* f;
	int a;
	scanf("%d", &a);
	
	if (a>10) {
		strcpy (mode, "r");
	}
	else {
		strcpy (mode, "w");
	}
	f = fopen("dat.dat", mode);
	if (f == NULL) { return 1; }
	
	fgets (buf, 255, f);
	printf ("%s", buf);
	fclose(f);		
	return 0;
}
