//Classification: #default/n/DAM/NP/gS/D(v)/lc/rp+cd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>

int a;

int main(void) 
{
int *p = NULL;
a = 1;
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
