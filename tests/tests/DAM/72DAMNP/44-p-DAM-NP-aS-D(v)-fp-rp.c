//Classification: #default/p/DAM/NP/aS/D(v)/fp/rp
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>

int *func(int *q) 
{
int *p = q;
return p;
};

int main(void) 
{
int a;
int b = 1;
int i;
  	for(i=1; i<100; i++) {
	    	a = *func(&b);
		printf("%d %d",a,b);
	}
return 0;
}
