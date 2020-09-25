//Classification: #default/n/DAM/NP/sS/D(v)/lc/cd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>

int main(void) 
{
int *p = NULL;
static int a = 1;
int c;
scanf("%d",&c);
	if (c==1) 
		a = *p;
printf("%d %d",a,c);
return 0;
}
