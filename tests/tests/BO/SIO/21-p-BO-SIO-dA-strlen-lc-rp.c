//Classification: #intrinsic/p/BO/SIO/dA/strlen/lc/rp
//Written by: Igor Eremeev
//Reviewed by: Pomelov Sergey
//Comment: buffer overflow using strlen

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (void)
{
	int *p, i;
	unsigned int a;
	char buf[100];
	
	p = (int*)malloc(sizeof(int) * 50);
	if (p == 0) { return 1; }
	
	strcpy (buf, "blablablablablablablablablablablablabla");
	
	a = strlen(buf);
	
	for(i = 0; i<a; i++) {
		p[i] = i;
	}
	
	
	printf ("%d\n", p[a-1]);
	printf ("%s\n", buf);	
	
	free(p);
	return 0;
}
