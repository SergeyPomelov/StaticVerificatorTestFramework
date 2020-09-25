//Classification: #default/n/DAM/NP/aS/D(v)/fp/ln
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
int a;
a = *func(NULL);
printf("%d",a);
return 0;
}
