//Classification: #default/p/ML/UPO/dA/none/fpb/cd
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment: if a > 10 then malloc in 'func' has closing 'free'; otherwise 'func' isn`t called at all

#include <stdlib.h>
#include <stdio.h>

int func (int **p)
{
	*p = (int *)malloc(sizeof(int));
	if ((*p)==0) {
		return 1;
	}
	return 0;
}

int main(void)
{
	int *p[3], a;
	
	scanf ("%d", &a);
	
	if ( a > 10 ) {
		if ( func(&p[1]) == 1 ) { return 1; }
		
		*p[1] = 2345;
		printf ("%d", *p[1]);
		
		free(p[1]);
	}

	p[1] = &a;
	printf ("%d", *p[1]);
	
	return 0;
}
