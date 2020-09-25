//Classification: #default/n/ZD/AE/aS+dS/A(D(v),v)/fpb/cd+rp
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov

#include <malloc.h>
#include <stdio.h>

int func(int *p) {
	(*p)+=2;
	return 0;
}

int main(void) {
	int *p;
	int a = 6;
	int b;
	
	p = (int *)malloc(sizeof(int));
	if (p == 0) {
		return 1;
	}
	*p = 2;
	
	while (*p <= 7) {
		func(p);
		if (*p <= 5) {
			b = 1 / (a - *p);
			printf ("%d", b);
		}
		else {
			b = 1 / (a + *p);
			printf ("%d", b);
		}
	}
	
	free(p);
	return 0;
}
