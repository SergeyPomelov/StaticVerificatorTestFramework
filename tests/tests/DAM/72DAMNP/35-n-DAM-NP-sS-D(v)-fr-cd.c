//Classification: #default/n/DAM/NP/sS/D(v)/fr/cd
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
static int a = 1;
int c;
scanf("%d",&c);
    if (c==1) 
		a = *func();
printf("%d %d",a,c);
return 0;
}
