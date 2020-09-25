//Classification: #default/p/IVO/UIM/dS/D(v)/fpb/cd
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment:

#include <stdio.h>
#include <stdlib.h>

void func(int** p) {
	int b;
	(*p) = (int *)malloc(sizeof(int));
	if ((*p) == 0) return;
	scanf ("%d", &b);
	if (b>0) {
		(**p) = 10;
	}
	else {
		(**p) = 20;
	}
}

int main(void) 
{
	int *p;
	func(&p);
	if (p==0) {
		return 1;
	}
	printf ("%d", *p);
	free(p);
	return 0;
}
