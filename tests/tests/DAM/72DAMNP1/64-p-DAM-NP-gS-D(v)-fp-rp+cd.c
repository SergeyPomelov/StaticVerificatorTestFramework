//Classification: #default/p/DAM/NP/gS/D(v)/fp/rp+cd
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
int b = 1;
int c;
int i;
a = 1;
scanf("%d",&c);
  for(i=1; i<100; i++) {
    if (c==i) 
		a = *func(&b);
  }
printf("%d %d %d",a,b,c);
return 0;
}

