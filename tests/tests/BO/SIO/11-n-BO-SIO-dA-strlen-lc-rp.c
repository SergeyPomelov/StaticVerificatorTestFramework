//Classification: #intrinsic/n/BO/SIO/dA/strlen/lc/rp
//Written by: Igor Eremeev
//Reviewed by: Pomelov Sergey
//Comment: buffer overflow using strlen

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (void)
{
	int *p, i;
	char buf[100];
	unsigned int a;
	
	p = (int*)malloc(sizeof(int) * 50);
	if (p == 0) { return 1; }
	
	fgets (buf, 100, stdin);
	a = strlen(buf);
	
	for(i = 0; i<a; i++) {
		p[i] = i;
	}
	
	printf ("%d", p[a-1]);	
	
	free(p);
	return 0;
}
