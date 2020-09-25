//Classification: #default/p/DAM/NP/gS/D(v)/lc/rp
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>

int a;

int main(void) 
{
int q = 1;
int *p = &q;
int i;
	for(i=1; i<100; i++) {
		a = *p;
	}
printf("%d %d",a,q);
return 0;
}
