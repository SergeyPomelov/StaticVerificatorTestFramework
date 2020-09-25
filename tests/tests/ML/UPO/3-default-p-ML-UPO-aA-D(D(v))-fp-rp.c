//Classification: #default/p/ML/UPO/aA/D(D(v))/fp/rp
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment:  memory is allocated at *(*(p+i))

#include <stdlib.h>
#include <stdio.h>

void func_free(int i, int **p) {
	int j;
	for (j = 0; j<i; j++) {
		free (p[j]);
	}
}

int main(void)
{
	int *p[10], i;
	
	for (i = 0; i<=9; i++) {
		p[i] = (int*)malloc(sizeof(int));
		if (p[i] == 0) {
			func_free(i, p);
			return 1;
		}
		*p[i] = 10*i;
		printf ("%d", *p[i]);
	}
	
	func_free(10, p);

	return 0;
}
