//Classification: p/DAM/NP/sS/D(v)/lc/cd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>

int main(void) 
{
int q = 2;
int *p = &q;
static int a = 1;
int c;
scanf("%d",&c);
	if (c==1) 
		a = *p;
printf("%d %d %d",a,c,q);
return 0;
}
