//Classification: #default/n/DAM/NP/aS/D(v)/fr/ln
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>

int *func(void) 
{
int *p = NULL;
return p;
};

int main(void) 
{
int a;
a = *func();
printf("%d",a);
return 0;
}
