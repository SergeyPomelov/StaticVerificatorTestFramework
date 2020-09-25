//Classification: #default/p/IVO/UIM/dA/D(v,c)/fpb/rp
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment:

#include <stdio.h>
#include <stdlib.h>

void func(int** p) {
	int i;
	(*p) = (int *)malloc(sizeof(int)*10);
	if ((*p) == 0) return;
	for (i = 0; i<10; i++) {
		(*((*p)+i)) = i;
	}
}	

int main(void) 
{
	int *p;
	func(&p);
	if (p==0) {
		return 1;
	}
	printf ("%d", *(p+6));
	free(p);
	return 0;
}
