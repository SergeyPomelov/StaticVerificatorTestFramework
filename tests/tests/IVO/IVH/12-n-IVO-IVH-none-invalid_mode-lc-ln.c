//Classification: #specific_error/n/IVO/IVH/aA+aS/invalid_mode/lc/cd
//Written by: Igor Eremeev
//Reviewed by: Pomelov Sergey
//Comment:  incorrect string

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	char buf[256];
	FILE* f;

	f = fopen("dat.dat", "123abc");
	if (f == NULL) { return 1; }
	
	fgets (buf, 255, f);
	printf ("%s", buf);
	
	fclose(f);		
	return 0;
}
