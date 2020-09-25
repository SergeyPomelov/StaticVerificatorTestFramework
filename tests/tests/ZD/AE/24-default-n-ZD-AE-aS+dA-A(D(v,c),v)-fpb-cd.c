//Classification: #default/n/ZD/AE/aS+dA/A(D(v,c),v)/fpb/cd
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov

#include <malloc.h>
#include <stdio.h>

int func(int *p) {
	p[0]+=1;
	p[1]+=2;
	p[2]+=3;
	return 0;
}

int main(void) {
	int *p;
	int a = 6;
	int b;
	
	p = (int *)malloc(sizeof(int) * 3);
	if (p == 0) {
		return 1;
	}
	p[0] = 3;
	p[1] = 3;
	p[2] = 5;
	
	if (p[1] <= 4) {
		func (p);
	}

	b = 1 / (a - p[1]);
	printf ("%d", b);

	free(p);
	return 0;
}
