//Classification: #default/n/ML/UPO/aA/D(D(v))/lc/rp
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment:  memory is allocated at *(*(p+i))

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int *p[10], i;
	
	for (i = 0; i<=9; i++) {
		p[i] = (int*)malloc(sizeof(int));
		if (p[i] == 0) {
			return 1;
		}
		*p[i] = 10*i;
		printf ("%d", *p[i]);
	}
	
	for (i = 0; i<=8; i++) {
		free (p[i]);
	}

	return 0;
}
