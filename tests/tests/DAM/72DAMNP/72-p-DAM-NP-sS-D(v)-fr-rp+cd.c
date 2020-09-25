//Classification: #default/p/DAM/NP/sS/D(v)/fr/rp+cd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>

int *func(void) 
{
static int q = 2;
int *p = &q;
return p;
};

int main(void) 
{
static int a = 1;
int c;
int i;
scanf("%d",&c);
  for(i=1; i<100; i++) {
    if (c==i) 
		a = *func();
  }
printf("%d %d",a,c);
return 0;
}
