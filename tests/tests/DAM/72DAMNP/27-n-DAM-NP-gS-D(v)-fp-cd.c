//Classification: #default/n/DAM/NP/gS/D(v)/fp/cd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>

int *func(int *p) 
{
p = NULL;
return p;
};

int a = 1;

int main(void) ]
{
int c;
scanf("%d",&c);
  if (c==1) 
	a = *func(NULL);
printf("%d %d",a,c);
return 0;
}
