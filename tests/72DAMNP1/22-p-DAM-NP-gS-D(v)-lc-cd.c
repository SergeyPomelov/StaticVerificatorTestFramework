//Classification: p/DAM/NP/gS/D(v)/lc/cd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>

int a = 1;

int main(void) 
{
int q = 2;
int *p = &q;
int c;
scanf("%d",&c);
	if (c==1) 
		a = *p;
printf("%d %d %d",a,c,q);
return 0;
}
