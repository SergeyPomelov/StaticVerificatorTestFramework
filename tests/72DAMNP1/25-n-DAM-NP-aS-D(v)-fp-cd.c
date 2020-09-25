//Classification: n/DAM/NP/aS/D(v)/fp/cd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>

int *func(int *p) 
{
return p;
};

int main(void) 
{
int a = 1;
int c;
scanf("%d",&c);
  if (c==1) 
	a = *func(NULL);
printf("%d %d",a,c);
return 0;
}
