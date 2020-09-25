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
	
	strcpy (buf, "blablablablablablablablablablablablablablablablablabla");
	
	a = strlen(buf);
	p[a] = a;
	
	printf ("%d\n", p[a]);
	printf ("%s\n", buf);	
	
	free(p);
	return 0;
}
