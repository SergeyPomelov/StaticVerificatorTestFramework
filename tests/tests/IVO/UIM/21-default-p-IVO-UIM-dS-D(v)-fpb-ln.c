//Classification: #default/p/IVO/UIM/dS/D(v)/fpb/ln
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment:

#include <stdio.h>
#include <stdlib.h>

void func(int** p) {
	(*p) = (int *)malloc(sizeof(int));
	if ( (*p) == 0) return;
	(**p) = 10;
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
