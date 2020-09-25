//Classification: #intrinsic/n/BO/SIO/dA/strlen/lc/ln
//Written by: Igor Eremeev
//Reviewed by: Pomelov Sergey
//Comment: buffer overflow using strlen

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (void)
{
	int *p;
	unsigned int a;
	char buf[100];
	
	p = (int*)malloc(sizeof(int) * 50);
	if (p == 0) { return 1; }
	
	fgets (buf, 100, stdin);
	a = strlen(buf);
	p[a] = a;
	
	printf ("%d", p[a]);	
	
	free(p);
	return 0;
}
