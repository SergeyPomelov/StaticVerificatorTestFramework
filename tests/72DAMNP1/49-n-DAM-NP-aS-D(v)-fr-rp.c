//Classification: n/DAM/NP/aS/D(v)/fr/rp
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>

int *func(void) 
{
int *p;
return p;
};

int main(void) 
{
int a;
int i;
	for(i=1; i<100; i++) {
	a = *func();
	printf("%d",a);
	}
return 0;
}
