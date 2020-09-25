//Classification: n/DAM/NP/gS/D(v)/fp/rp
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>

int *func(int *p) 
{
p = NULL;
return p;
};

int a ;

int main(void) 
{
int i;
	for(i=1; i<100; i++) {
	a = *func(NULL);
	printf("%d",a);
	}
return 0;
}
