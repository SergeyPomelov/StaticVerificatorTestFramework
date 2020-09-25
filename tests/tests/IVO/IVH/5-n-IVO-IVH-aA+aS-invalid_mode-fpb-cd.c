//Classification: #specific_error/n/IVO/IVH/aA+aS/invalid_mode/fpb/cd
//Written by: Igor Eremeev
//Reviewed by: Pomelov Sergey
//Comment:  generating mode string incorrectly

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int func(char *pc, int a)
{
	if (a>10) {
		strcat (pc, "123");
	}
	return 0;
}


int main(void)
{
	char mode[5] = "r", buf[256];
	FILE* f;
	int a;
	scanf("%d", &a);
	
	if ( func(mode, a) == 1 ) {return 1;}

	f = fopen("dat.dat", mode);
	if (f == NULL) { return 1; }
	
	fgets (buf, 255, f);
	printf ("%s", buf);
	
	fclose(f);		
	return 0;
}
