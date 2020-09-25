//Classification: #specific_error/n/IVO/IVH/none/invalid_mode/lc/ln
//Written by: Igor Eremeev
//Reviewed by: Pomelov Sergey
//Comment:  create mode string incorrectly ('rw' is not a valid value)

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	char mode[5] = "r", buf[256];
	FILE* f;
	int a;
	scanf("%d", &a);
	
	if (a>10) {
		strcat (mode, "w");
	}
	f = fopen("dat.dat", mode);
	if (f == NULL) { return 1; }
	
	fgets (buf, 255, f);
	printf ("%s", buf);
	fclose(f);		
	return 0;
}
