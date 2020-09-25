//Classification: #default/n/ZD/AE/aS+dA/A(D(v,v),c)/lc/ln
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov

#include <malloc.h>
#include <stdio.h>

int main(void) {
	int *p;
	int a = 2;
	int b;
	
	p = (int *)malloc(sizeof(int) * 3);
	if (p == 0) {
		return 1;
	}
	p[2] = 6;

	b = 1 / (p[a]-6);
	printf ("%d", b);

	free(p);
	return 0;
}
