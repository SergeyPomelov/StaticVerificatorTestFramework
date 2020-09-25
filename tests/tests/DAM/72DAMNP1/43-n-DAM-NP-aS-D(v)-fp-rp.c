//Classification: #default/n/DAM/NP/aS/D(v)/fp/rp
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>

int *func(int *p) 
{
return p;
};

int main(void) 
{
int a ;
int i;
	for(i=1; i<100; i++) {
		a = *func(NULL);
		printf("%d",a);
	}
return 0;
}
