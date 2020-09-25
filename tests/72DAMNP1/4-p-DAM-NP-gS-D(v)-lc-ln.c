//Classification: p/DAM/NP/gS/D(v)/lc/ln
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include <stdio.h>

int main(void) 
{
int q = 1;
int *p = &q;
extern int a;
a = *p;
printf("%d %d",a,q);
return 0;
}
