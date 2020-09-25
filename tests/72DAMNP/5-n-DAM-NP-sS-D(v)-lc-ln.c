//Classification: n/DAM/NP/sS/D(v)/lc/ln
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>

int main(void) 
{
int *p = NULL;
static int a;
a = *p;
printf("%d",a);
return 0;
}
