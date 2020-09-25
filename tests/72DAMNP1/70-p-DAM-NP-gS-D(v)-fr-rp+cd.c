//Classification: p/DAM/NP/gS/D(v)/fr/rp+cd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>

int *func(void) 
{
static int q = 1;
int *p = &q;
return p;
};

int a;

int main(void) 
{
int c;
int i;
a = 1;
scanf("%d",&c);
for(i=1; i<100; i++) {
	if (c==i) 
		a = *func();
}
printf("%d %d",a,c);
return 0;
}
