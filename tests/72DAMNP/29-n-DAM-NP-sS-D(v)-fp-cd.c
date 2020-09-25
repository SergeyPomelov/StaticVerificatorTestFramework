//Classification: n/DAM/NP/sS/D(v)/fp/cd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>

int *func(int *p) 
{
p = NULL;
return p;
};

int main(void) 
{
static int a = 1;
int c;
scanf("%d",&c);
  if (c==1) 
	a = *func(NULL);
printf("%d %d",a,c);
return 0;
}
