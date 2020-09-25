//Classification: p/DAM/NP/sS/D(v)/fp/ln
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
static int a;
int b = 1;
a = *func(&b);
printf("%d %d",a,b);
return 0;
}
