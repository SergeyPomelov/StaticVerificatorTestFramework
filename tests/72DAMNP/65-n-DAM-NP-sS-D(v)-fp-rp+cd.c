//Classification: n/DAM/NP/sS/D(v)/fp/rp+cd
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
int i;
scanf("%d",&c);
  for(i=1; i<100; i++) {
    if (c==i) 
		a = *func(NULL);
  }
printf("%d %d",a,c);
return 0;
}
