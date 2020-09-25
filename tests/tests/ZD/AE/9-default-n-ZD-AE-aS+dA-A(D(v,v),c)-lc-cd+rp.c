//Classification: #default/n/ZD/AE/aS+dA/A(D(v,v),c)/lc/cd+rp
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov

#include <malloc.h>
#include <stdio.h>

int main(void) {
	
	int a = 0;
	int b;
	
	int *p;
	p = (int *)malloc(sizeof(int) * 3);
	if (p == 0) {
		return 1;
	}
	p[2] = 4;
	p[1] = 5;
	p[0] = 6;
	
	while (a < 2) {
		a++;
		if (a == 2) {
			b = 1 / (p[a]-4);
			printf ("%d", b);
		}
	}
	
	free(p);
	return 0;
}
