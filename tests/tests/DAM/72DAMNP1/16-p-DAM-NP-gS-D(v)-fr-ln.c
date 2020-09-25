//Classification: #default/p/DAM/NP/gS/D(v)/fr/ln
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
a = *func();
printf("%d",a);
return 0;
}
