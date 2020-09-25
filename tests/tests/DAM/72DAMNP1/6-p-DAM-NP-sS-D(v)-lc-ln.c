//Classification: #default/p/DAM/NP/sS/D(v)/lc/ln
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>

int main(void) 
{
int q = 1;
int *p = &q;
static int a;
a = *p;
printf("%d %d",a,q);
return 0;
}
