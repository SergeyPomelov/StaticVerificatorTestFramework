//Classification: n/DAM/NP/gS/D(v)/fp/ln
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>

int *func(int *q) 
{
int *p = q;
return p;
};

int a;

int main(void) 
{
a = *func(NULL);
printf("%d",a);
return 0;
}
