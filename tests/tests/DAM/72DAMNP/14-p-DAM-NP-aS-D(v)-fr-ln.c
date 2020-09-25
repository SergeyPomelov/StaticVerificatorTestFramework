//Classification: #default/p/DAM/NP/aS/D(v)/fr/ln
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

int main(void) 
{
int a;
a = *func();
printf("%d",a);
return 0;
}
