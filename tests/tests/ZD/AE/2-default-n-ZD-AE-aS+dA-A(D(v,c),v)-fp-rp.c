//Classification: #default/n/ZD/AE/aS+dA/A(D(v,c),v)/fp/rp
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov

#include <malloc.h>
#include <stdio.h>

int func(int *p) {
	int a = 3, b = 2, c = 5, d;
	d = 1/(p[0]-a);
	printf ("%d", d);
	d = 1/(p[1]-b);
	printf ("%d", d);
	d = 1/(p[2]-c);
	printf ("%d", d);
	return 0;
}

int main(void) {
	int *p;
	int a = 3;
	
	p = (int *)malloc(sizeof(int) * 3);
	if (p == 0) {
		return 1;
	}

	p[0] = 6;
	p[1] = 5;
	
	while (a <= 5) {
		p[2] = a++;	
		func(p);
	}
	
	free(p);
	return 0;
}
