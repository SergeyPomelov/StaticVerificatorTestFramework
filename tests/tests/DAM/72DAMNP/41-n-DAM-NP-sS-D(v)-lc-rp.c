//Classification: #default/n/DAM/NP/sS/D(v)/lc/rp
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>

int main(void) 
{
int *p = NULL;
static int a;
int i;
	for(i=1; i<100; i++) {
		a = *p;
		printf("%d",a);
	}
return 0;
}
