//Classification: #default/n/DAM/NP/gS/D(v)/lc/rp
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>

int a;

int main(void) 
{
int *p = NULL;
int i;
	for(i=1; i<100; i++) {
		a = *p;
	}
printf("%d",a);
return 0;
}
