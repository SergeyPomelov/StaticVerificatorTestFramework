//Classification: #default/n/DAM/NP/gS/D(v)/fr/ln
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>

int *func(void) 
{
int *p;
return p;
};

int a;

int main(void) 
{
a = *func();
printf("%d",a);
return 0;
}
