//Classification: n/DAM/NP/sS/D(v)/lc/rp+cd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>

int main(void) 
{
int *p;
static int a = 1;
int c = 1;
int i;
scanf("%d",&c);
  for(i=1; i<100; i++) {
    if (c==i) 
		a = *p;
  }
printf("%d %d",a,c);
return 0;
}
